// This is a bad level XML parsing option, a temporary solution to understand the structure of the XMl files

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string line;
    ifstream in("demo.xml");

    bool begin_tag = false;
    while (getline(in,line))
    {
        std::string tmp; // strip whitespaces from the beginning
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ' ' && tmp.size() == 0)
            {
            }
            else
            {
                tmp += line[i];
            }
        }

        //cout << "-->" << tmp << "<--" << endl;

        if (tmp == "<Package>")
        {
            //cout << "Found <Package>" << endl;
            begin_tag = true;
            continue;
        }
        else if (tmp == "</Package>")
        {
            begin_tag = false;
            //cout << "Found </Package>" << endl;
        }

        if (begin_tag)
        {
            cout << tmp << endl;
        }
    }
}