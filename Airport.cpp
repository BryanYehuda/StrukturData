#include <iostream>
#include <cmath>
#include <time.h>
#include <climits>
#define max_int __INT32_MAX__
using namespace std;

const int plane_limit = 10000;
enum Error_code {success, overflow, underflow, fail};
enum Plane_status {null, arriving, departing};

class Plane 
{
    public:
        Plane();
        Plane(int fit, int time, Plane_status status);
        void refuse() const;
        void land(int time) const;
        void fly(int time) const;
        int started() const;

    private:
        int fit_num;
        int clock_start;
        Plane_status state;
};

class Extended_queue 
{
    public:
        Extended_queue();
        void serve();
        Error_code append(const Plane &item);
        void retrieve(Plane &item);
        bool empty() const;
        void clear();
        bool full() const;
        int size() const;
    
    private:
        int count;
        int index;
        int rear;
        Plane entry[plane_limit];
};

enum Runway_activity {idle, land, takingoff};
class Runway 
{
    public:
        Runway(int limit);
        Error_code can_land(const Plane &current);
        Error_code can_depart(const Plane &current);
        Runway_activity activity(int time, Plane &moving);
        void shut_down(int time) const;

    private:
        Extended_queue landing;
        Extended_queue takeoff;
        int queue_limit;
        int num_land_requests;
        int num_takeoff_requests;
        int num_landings;
        int num_takeoffs;
        int num_land_accepted;
        int num_takeoff_accepted;
        int num_land_refused;
        int num_takeoff_refused;
        int land_wait;
        int takeoff_wait;
        int idle_time;
};

class Random 
{
    public:
        Random(bool pseudo = true);
        int poisson(double mean);
        double random_real();
    
    private:
        int reseed();
        int seed, multiplier, add_on;
};

void initialize(int &end_time, int &queue_limit, double &arrival_rate, double &departure_rate) 
{
    cout << "This program simulates an airport with only one runway" << endl << "One plane can land or depart in each unit of time" << endl;
    cout << "Up to what number of planes can be waiting to land" << " or take off at any time?" << flush;
    cin >> queue_limit;
    cout << "How many units of time will the simulation run?" << flush;
    cin >> end_time;
    bool acceptable;
    do 
	{
        cout << "Expected number of arrivals per unit time?" << flush;
        cin >> arrival_rate;
        cout << "Expected number of departures per unit time?" << flush;
        cin >> departure_rate;
        if (arrival_rate < 0.0 || departure_rate < 0.0)
            cerr << "These rates must be nonnegative" << endl;
        else
            acceptable = true;
        if (acceptable && arrival_rate + departure_rate > 1.0)
            cerr << "Safety Warning: This airport will become saturated" << endl;
    } while (!acceptable);
}

void run_idle(int time) 
{
    cout << time << ": Runway is idle" << endl;
}

int main() 
{
    int end_time;
    int queue_limit;
    int flight_number = 0;
    double arrival_rate, departure_rate;
    initialize(end_time, queue_limit, arrival_rate, departure_rate);
    Random variable;
    Runway small_airport(queue_limit);
    for (int current_time = 0; current_time < end_time; current_time++) 
	{
        
        int number_arrivals = variable.poisson(arrival_rate);

        for (int i = 0; i < number_arrivals; i++) 
		{
            Plane current_plane(flight_number++, current_time, arriving);
            if (small_airport.can_land(current_plane) != success)
                current_plane.refuse();
        }

        int number_departures = variable.poisson(departure_rate);

        for (int j = 0; j < number_departures; j++) 
		{
            Plane current_plane(flight_number++, current_time, departing);
            if (small_airport.can_depart(current_plane) != success)
                current_plane.refuse();
        }

        Plane moving_plane;
        switch (small_airport.activity(current_time, moving_plane)) 
		{
            case land:
                moving_plane.land(current_time);
                break;
            case takingoff:
                moving_plane.fly(current_time);
                break;
            case idle:
                run_idle(current_time);
        }
    }
    small_airport.shut_down(end_time);

    return 0;
}

Extended_queue::Extended_queue() 
{
    index = 0;
    count = 0;
    rear = plane_limit - 1;
}

Error_code Extended_queue::append(const Plane &item)
 {
    if (count >= plane_limit) return overflow;
    count++;
    rear = ((rear + 1) == plane_limit)?0:(rear+1);
    entry[rear] = item;
    return success;
}

void Extended_queue::serve() 
{
    count--;
    index = ((index + 1) == plane_limit)?0:(index + 1);
}

void Extended_queue::retrieve(Plane &item) 
{
    item = entry[index];
}

bool Extended_queue::empty() const 
{
    return count == 0;
}

void Extended_queue::clear() 
{
    index = count = 0;
}

bool Extended_queue::full() const 
{
    return count == plane_limit;
}

int Extended_queue::size() const 
{
    return count;
}

// Runway init
Runway::Runway(int limit) 
{
    queue_limit = limit;
    num_land_requests = num_takeoff_requests = 0;
    num_landings = num_takeoffs = 0;
    num_land_refused = num_takeoff_refused = 0;
    num_land_accepted = num_takeoff_accepted = 0;
    land_wait = takeoff_wait = idle_time = 0;
}

// accept plane to runway
Error_code Runway::can_land(const Plane &current) 
{
    Error_code result;
    if (landing.size() < queue_limit)
        result = landing.append(current);
    else
        result = fail;
    
    num_land_requests++;
    if (result != success) 
        num_land_refused++;
    else
        num_land_accepted++;
    return result;
}

Error_code Runway::can_depart(const Plane &current) 
{
    Error_code result;
    if (takeoff.size() < queue_limit)   
        result = takeoff.append(current);
    else
        result = fail;
    
    num_takeoff_requests++;
    if (result != success) 
        num_takeoff_refused++;
    else
        num_takeoff_accepted++;
    return result;
}

Runway_activity Runway::activity(int time, Plane &moving) 
{
    Runway_activity in_progress;
    if (!landing.empty()) {
        landing.retrieve(moving);
        land_wait += time - moving.started();
        num_landings++;
        in_progress = land;
        landing.serve();
    }
    else if (!takeoff.empty()) {
        takeoff.retrieve(moving);
        takeoff_wait += time - moving.started();
        num_takeoffs++;
        in_progress = takingoff;
        takeoff.serve();
    }
    else {
        idle_time++;
        in_progress = idle;
    }
    return in_progress;
}

void Runway::shut_down(int time) const 
{
    cout << "Simulation has concluded after " << time << " time units" << endl << "Total number of planes processed " << (num_land_requests + num_takeoff_requests) << endl << "Total number of planes asking to land " << num_land_requests << endl << "Total number of planes asking to take off " << num_takeoff_requests << endl << "Total number of planes accepted for landing " << num_land_accepted << endl << "Total number of planes accepted for takeoff " << num_takeoff_accepted << endl << "Total number of planes refused for landing " << num_land_refused << endl << "Total number of planes refused for takeoff " << num_takeoff_refused << endl << "Total number of planes that landed " << num_landings << endl << "Total number of planes that took off " << num_takeoffs << endl << "Total number of planes left in landing queue " << landing.size( ) << endl << "Total number of planes left in takeoff queue " << takeoff.size( ) << endl;
    cout << "Percentage of time runway idle " << 100.0 * ((float) idle_time)/((float) time) << "%" << endl;
    cout << "Average wait in landing queue " << ((float) land_wait)/((float) num_landings) << " time units";
    cout << endl << "Average wait in takeoff queue " << ((float) takeoff_wait)/((float) num_takeoffs) << " time units" << endl;
    cout << "Average observed rate of planes wanting to land " << ((float) num_land_requests)/((float) time) << " per time unit" << endl;
    cout << "Average observed rate of planes wanting to take off " << ((float) num_takeoff_requests)/((float) time) << " per time unit" << endl;
}

Plane::Plane(int fit, int time, Plane_status status) 
{
    fit_num = fit;
    clock_start = time;
    state = status;
    cout << "Plane number " << fit << " ready to ";
    if (status == arriving) 
        cout << "land" << endl;
    else
        cout << "take off" << endl;
}

Plane::Plane() 
{
    fit_num = -1;
    clock_start = -1;
    state = null;
}

void Plane::refuse() const 
{
    cout << "Plane number " << fit_num;
    if (state == arriving) 
        cout << " directed to another airport" << endl;
    else 
        cout << " told to try to takeoff again later" << endl;
}

void Plane::land(int time) const 
{
    int wait = time - clock_start;
    cout << time << ": Plane number " << fit_num << " landed after " << wait << " time unit" << ((wait == 1)? "":"s") << " in the takeoff queue" << endl;
}

void Plane::fly(int time) const 
{
    int wait = time - clock_start;
    cout << time << ": Plane number " << fit_num << " took off after " << wait << " time unit" << ((wait == 1)? "":"s") << " in the takeoff queue" << endl;
}

int Plane::started() const 
{
    return clock_start;
}

Random::Random(bool pseudo) 
{
    if (pseudo) seed = 1;
    else seed = time(NULL) % max_int;
    multiplier = 2743;
    add_on = 5923;
}

int Random::reseed() 
{
    seed = seed * multiplier + add_on;
    return seed;
}

double Random::random_real() 
{
    double max = max_int + 1.0;
    double temp = reseed();
    if (temp < 0) temp = temp + max;
    return temp/max;
}

int Random::poisson(double mean) 
{
    double limit = exp(-mean);
    double product = random_real();
    int count = 0;
    while (product > limit) {
        count++;
        product *= random_real();
    }
    return count;
}
