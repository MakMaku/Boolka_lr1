#include "TClient.h"
#include <chrono>
using namespace std;
using namespace chrono;

int main(){
    system("title UDP Client");
    TMessage message;
    TClient client;
    client.set_port(12346);
    client.set_ipaddres("127.0.0.1");
    client.Creat_Socket();
    double time = 0;
    time_point<steady_clock> Tstart, Tend = steady_clock::now(), Tbegin = steady_clock::now();;
    while (time <=100) {
        time = duration<double>(Tend - Tbegin).count();
        message.timelabel = time;
        message.longitude = 30 + sin(2 * time);
        message.latitude = 55 + cos(-3 * time);
        message.H = 2 * time;
        message.Vput = 140;
        message.pitch = 45.5;
        message.roll = 0;
        message.yaw = sin(time / 57.3);
        cout << "***************************************************************\n";
        cout << "T: " << time << endl;
        cout << "Lon: " << message.longitude << "\tLat: " << message.latitude << "\tH: " << message.H << "\tVput: " << message.Vput << endl;
        cout << "Pitch: " << message.pitch << "\tRoll: " << message.roll << "\tYaw: " << message.yaw << endl;
        time += 1.1;
        client.Send(message);
        Tstart = steady_clock::now();
        Tend = steady_clock::now();
        while (duration_cast<milliseconds>(Tend - Tstart).count() <= 100) {
            Tend = steady_clock::now();
        }
    }
    client.Clean_n_Close();
}
