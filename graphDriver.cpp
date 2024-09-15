#include "graph.h"
#include <iostream>

int main()
{
    std::string command;
    Graph g;
    while (std::cin >> command)
    {
        if (command == "LOAD")
        {
            std::string filename;
            std::cin >> filename;
            std::fstream fin(filename.c_str());
            g.load(fin);
            std::cout << "success\n";
        }
        else if (command == "INSERT")
        {
            int a, b;
            double d, s;
            std::cin >> a >> b >> d >> s;
            try
            {
                g.insertEdge(a, b, d, s);
                std::cout << "success\n";
            }
            catch (illegal_exception &e)
            {
                std::cout << e.what();
            }
        }

        else if (command == "PRINT")
        {
            int a;
            std::cin >> a;
            try
            {
                g.print(a);
            }
            catch (illegal_exception &e)
            {
                std::cout << e.what();
            }
        }

        else if (command == "DELETE")
        {
            int a;
            std::cin >> a;
            try
            {
                g.remove(a);
            }
            catch (illegal_exception &e)
            {
                std::cout << e.what();
            }
        }

        else if (command == "PATH")
        {
            int a, b;
            std::cin >> a >> b;
            try
            {
                g.path(a, b);
            }
            catch (illegal_exception &e)
            {
                std::cout << e.what();
            }
        }

        else if (command == "TRAFFIC")
        {
            int a, b;
            double adjustmentFactor;
            std::cin >> a >> b >> adjustmentFactor;
            try
            {
                g.traffic(a, b, adjustmentFactor);
            }
            catch (illegal_exception &e)
            {
                std::cout << e.what();
            }

        }

        else if (command == "UPDATE")
        {
            std::string filename;
            std::cin >> filename;
            std::fstream fin(filename.c_str());
            g.update(fin);
        }

        else if (command == "LOWEST")
        {
            int a, b;
            std::cin >> a >> b;
            try
            {
                g.lowest(a, b);
            }
            catch (illegal_exception &e)
            {
                std::cout << e.what();
            }
        }

        else if (command == "EXIT")
        {
            break;
        }
    }
    return 0;
}