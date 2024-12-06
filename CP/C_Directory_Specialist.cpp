#include <bits/stdc++.h>
using namespace std;
struct node
{
    string nodePath;
    map<string, node *> mp;
};

stack<node *> stk;

int main()
{
    string command;

    node *rootNode = new node;
    rootNode->nodePath = "KGS";
    stk.push(rootNode);

    while (getline(cin, command))
    {
        stringstream ss(command);
        string cmd;
        ss >> cmd;

        node *currdir = stk.top();

        if (cmd == "mkdir")
        {
            string subdir;
            ss >> subdir;

            if (currdir->mp.count(subdir))
                cout << "Error: Already Exists" << endl;
            else
            {
                node *newNode = new node();
                newNode->nodePath = currdir->nodePath + "/" + subdir;
                currdir->mp[subdir] = newNode;
            }
        }
        else if (cmd == "cd")
        {
            string subcom;
            ss >> subcom;

            if (subcom == "..")
            {
                if (stk.size() > 1)
                    stk.pop();
            }
            else
            {
                if (currdir->mp.find(subcom) == currdir->mp.end())
                    cout << "Error: No Such Directory" << endl;
                else
                    stk.push(currdir->mp[subcom]);
            }
        }
        else if (cmd == "ls")
        {
            for (auto it = currdir->mp.begin(); it != currdir->mp.end(); it++)
                cout << it->first << endl;
        }
        else if (cmd == "rm")
        {
            string subdir;
            ss >> subdir;

            if (currdir->mp.find(subdir) == currdir->mp.end())
                cout << "Error: No Such Directory" << endl;
            else
                currdir->mp.erase(subdir);
        }
        else if (cmd == "pwd")
        {
            cout << stk.top()->nodePath << endl;
        }
    }
    return 0;
}
