#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
string executeAndRead(const char *);
int characterIdxFromString(string, char);

const char * cmd("./temper");

int main() 
{
    string result = executeAndRead(cmd);
    int idx = characterIdxFromString(result, ',');

    int strLen= result.length() - idx - 1;

    string tempStr = result.substr(idx + 1, strLen);

    double temp = atof(tempStr.c_str());
    temp -= 5; //Magnificent calibration of the sensor. Gotta look more into it..


    cout << "elikkäs: " << temp << " ... ebin!" << endl;
    return 0;
}

int characterIdxFromString(string str, char c)
{
    if(str.length() == 0)
    {
        return -1;
    }

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == c)
            return i;
    }

    return -1;
}

string executeAndRead(const char* cmd)
{
    FILE * pipe = popen(cmd, "r");

    if(!pipe) return "ERROR";

    char buffer[128];

    string result = "";

    while (!feof(pipe))
    {
        if (fgets(buffer, 128, pipe) != NULL)
                result += buffer;
    }

    pclose(pipe);
    return result;
}


