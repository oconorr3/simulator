#include "controller.h"
#include "randomlb.h"

#include <iostream>
int main() {
    Controller c(5, 10000, 550);
    RandomLoadBalancer lb(&c);
    lb.run(1500, true, 50);
    char file1[] = "time1.csv";
    c.printNodeValues(file1);

    lb.run(1500, true, 50);
    char file2[] = "time2.csv";
    c.printNodeValues(file2);

    lb.run(1500, true, 50);
    char file3[] = "time3.csv";
    c.printNodeValues(file3);

    lb.run(1500, true, 50);
    char file4[] = "time4.csv";
    c.printNodeValues(file4);

    lb.run(20000000, true, 50);
    char file5[] = "time6.csv";
    //c.printNodeValues(file5);



    c.shutdownController();
    return 0;
}