#include "Message.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

//bool checkIPvrPort(string);
bool setIP(string);
bool setPort(string);

Message::Message(std::string Messagedata) 
{
    this->data = Messagedata;
    this->contentLength = Messagedata.length();
    this->Encoding = "";
    this->Destination = "IP:Port";
    this->Origin = "IP:Port";
}

Message::Message(Message* msg)
{
    this->data = msg->getData();
    this->Encoding = "";
    this->Destination = "IP:Port";
    this->Origin = "IP:Port";
    this->contentLength = msg->getContentLength();
    //cout << this->contentLength << endl;

}

std::string Message::getData()
{
   return this->data; 
}

std::string Message::getDestination()
{
    string ans = "";
    //cout << this->Destination.substr(0, this->Destination.find(":")) << endl;
    //cout << this->Destination.substr(this->Destination.find(":")+1, this->Destination.size()) << endl;
    if (this->Destination.substr(0, this->Destination.find(":")) != "IP" && this->Destination.substr(this->Destination.find(":")+1, this->Destination.size()) != "Port" )
    ans = this->Destination;
    else
    ans = "ERROR: INCOMPLETE ADDRESS";

    return ans;
}

std::string Message::getOrigin()
{
    string ans = "";
    if (this->Origin.substr(0, this->Origin.find(":")) != "IP" && this->Origin.substr(this->Origin.find(":")+1, this->Origin.size()) != "Port" )
    ans = this->Origin;
    else
    ans = "ERROR: INCOMPLETE ADDRESS";

    return ans;
}

std::string Message::getEncoding()
{
    return this->Encoding;
}

std::string Message::getDestinationIP()
{
    string ans = "";
    if (this->Destination.substr(0,this->Destination.find(":")) == "IP")
    ans = "ERROR: IPV4 NOT SET";
    else
    ans = this->Destination.substr(0,this->Destination.find(":"));
    //cout << "NewYOrk: " << this->Destination << endl;
    return ans;
}

std::string Message::getDestinationPort()
{
    string temp = this->Destination;
    string ans = "";
    temp.erase(0, temp.find(":") +1);

    if (temp == "Port")
    ans = "ERROR: PORT NOT SET";
    else
    ans = temp;

    return ans;
}

std::string Message::getOriginIP()
{
    string ans = "";
    if (this->Origin.substr(0,this->Origin.find(":")) == "IP")
    ans = "ERROR: IPV4 NOT SET";
    else
    ans = this->Origin.substr(0,this->Origin.find(":"));

    return ans;    
}

std::string Message::getOriginPort()
{
    //cout << "NewYork: " << this->Origin << endl;
    string temp = this->Origin;
    string ans = "";
    temp.erase(0, temp.find(":") +1);

    if (temp == "Port")
    ans = "ERROR: PORT NOT SET";
    else
    ans = temp;

    return ans;    
}

bool Message::setDestinationIP(std::string DestIP)
{
    bool ans = true;
    if ((setIP(DestIP) == false) || (this->Destination.substr(0 ,this->Destination.find(":")) != "IP"))
    return false;
    // cout << "***********************" << endl;
    // cout <<this->Destination.substr(0 ,this->Destination.find(":")) << endl;
    //  cout << "***********************" << endl;
    // string ip = "";

    // for (int i = 1; i <= 3 ;i++)
    // {
    //     ip += DestIP.substr(0, DestIP.find(",")) + ".";
    //     DestIP.erase(0, DestIP.find(",") +1);
    // }

    // ip += DestIP;
    this->Destination.erase(0 ,this->Destination.find(":"));
    this->Destination.insert(0,DestIP);

    return ans;
}

bool Message::setDestinationPort(std::string DestPort)
{
    bool ans = true;
    string temp = this->Destination;
   
    temp.erase(0, temp.find(":")+1);
     //cout << "NewYOrk :" << temp << endl;
    //cout << "NewYOrk :" << setPort(DestPort) << endl;
    if (setPort(DestPort) == false || temp != "Port")
    return false;
    //cout << "NewYOrk :" << temp << endl;
    this->Destination.erase( this->Destination.find(":") +1, this->Destination.size());
    this->Destination.insert(this->Destination.find(":") +1, DestPort);

    return ans;
}

bool Message::setOriginIP(std::string OriginIP)
{
    //cout << "NewYork: " << this->Destination.substr(0 ,this->Destination.find(":"))  <<endl;
    bool ans = true;
    if ((setIP(OriginIP) == false) || (this->Origin.substr(0 ,this->Origin.find(":")) != "IP"))
    return false;

    // string ip = "";

    // for (int i = 1; i <= 3 ;i++)
    // {
    //     ip += OriginIP.substr(0, OriginIP.find(",")) + ".";
    //     OriginIP.erase(0, OriginIP.find(",") +1);
    // }

    // ip += OriginIP;
    this->Origin.erase(0 ,this->Origin.find(":"));
    this->Origin.insert(0,OriginIP);
    //cout << "NewYork: " << this->Origin << endl;
    return ans; 
}

bool Message::setOriginPort(std::string OriginPort)
{
    bool ans = true;
    string temp = this->Origin;
    temp.erase(0, temp.find(":")+1);
    if (setPort(OriginPort) ==false || temp != "Port")
    return false;

    this->Origin.erase( this->Origin.find(":") +1, this->Origin.size());
    this->Origin.insert(this->Origin.find(":") +1, OriginPort);

    return ans;    
}

void Message::setEncoding(std::string Encoding)
{
    this->Encoding = Encoding;    
}

void Message::PrintMessage() 
{
    cout << "Data: " << this->data << endl;
    cout << "Destination: " << this->getDestination() << endl;
    cout <<  "Destination IPV4: " << this->getDestinationIP() << endl;
    cout << "Destination Port: " << this->getDestinationPort() << endl;
    cout << "Origin: " << this->getOrigin() << endl;
    cout << "Origin IPV4: " << this->getOriginIP() << endl;
    cout << "Origin Port: " << this->getOriginPort() << endl;
    cout << "Encoding: " << this->Encoding << endl;
}

Message::~Message()
{
    cout << "Deleted message containing: " << this->data << endl;    
}

int Message::getContentLength()
{
    return this->contentLength;

}

void Message::setContentLength(int contentLength)
{
    this->contentLength = contentLength;
}

// bool checkIPvrPort(string data)
// {
//     bool ans = true;
//     int ip = 0, colon = 0;
//     if (data == "IP:Port")
//     {
//         ans = false;
//     }
//     else 
//     {
//         for (int i = 0; i < data.length(); i++)
//         {
//             if (data[i] == '.') ip++;
//             if (data[i] == ':') colon++;
//         }
//         if (ip != 3 || colon != 1)
//         {
//             ans = false;
//         }
//     }

//     return ans;
// }


bool setIP(string data)
{
    bool ans = true;
    int ip = 0;
    for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == '.')
            ip++;
        }

    ans = data.find_first_not_of("0123456789.") == std::string::npos;
    if (ip != 3 || ans == false)
    return false;
    
    
    stringstream x;
    int temp = 0;
    for (int i = 1; i <= 3;i++)
    {
        x << data.substr(0,data.find("."));
        x >> temp;
        if (temp < 0 || temp > 255)
        ans = false;
        data.erase(0,data.find(".") +1);
        x.clear(); 
    }
        x << data;
        x >> temp;
        if (temp < 0 || temp > 255)
        ans = false;
        x.clear(); 


    return ans;

}

bool setPort(string data)
{
    //string numbers = "0123456789";
    bool ans = true;
    int number;
    ans = data.find_first_not_of("0123456789") == std::string::npos;
    if (ans == false)
    return false;
    //cout << "Hello: " << ans << endl;
    stringstream x;
    x << data;
    x >> number;
    x.clear();
    //cout << "Hello: " << data << endl;
    if (number < 0 || number >65535)
    ans= false;
    //cout << "Hello: " << ans << endl;
    return ans;


}


