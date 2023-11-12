#include "TServer.h"
using namespace std;

int main(){
    system("title UDP Server");
    TServer server;
    server.set_port(12346);
    server.Creat_Socket();
    TMessage Message;
    while (true){
        Message = server.Receive();
        cout<<"\n***************************************************************\n";
        cout << "T: " << Message.timelabel << endl;
        cout << "Lon: " << Message.longitude << "\tLat: " << Message.latitude << "\tH: " << Message.H << "\tVput: " << Message.Vput << endl;
        cout << "Pitch: " << Message.pitch << "\tRoll: " << Message.roll << "\tYaw: " << Message.yaw << endl;
    }
    server.Clean_n_Close();
}

