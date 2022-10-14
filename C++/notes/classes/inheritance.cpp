#include <stdio.h>
class Parent
{
    protected: //cannot be accessed from outside class but can be from inherited class
               //means we may instantiate Parent in an object within main but cannot call object.protected_describe();
        void protected_describe()
        {
            printf("protected: I am a parent\n");
        }
    public:
        void public_describe()
        {
            printf("public: I am a parent\n");
        }
        virtual void describe()
        {
            printf("I am Parent\n");
        }
        void test_override() //If we want this to print out derived/child's version, we must make describe in Parent VIRTUAL
        {
            describe();
        }
    private: //cannot be accessed outside of this Parent class
        void private_describe()
        {
            printf("private: I am a parent\n");
        }
};

class Child1: public Parent //private/public modifier of Parent filters whether we can access parent by using child_object.Parent
                               //public, can be accessed from outside Child1 
                               //private, cannot be accessed from outside Child1 class
                               //protected, can be accessed from class that inherited Child1 (Instantiated Object CANNOT access obj.Parent)
{
    public:
        void describe()
        {
            printf("I am Child1\n");
        }
        void p_pb_describe()
        {
            Parent::public_describe(); //Can access parent method here
        }
        void p_pr_describe()
        {
            Parent::protected_describe(); //Can access parent method inside this inherited/child class definition
        }
        void p_priv_describe()
        {
            ;//Parent::private_describe() //CANNOT ACCESS
        }
};

int main()
{
    //Parent p;
    //p.describe();
    //Parent::describe(); //Does not work because describe is not static

    Child1 c1;
    //Calling public methods of Child1

    c1.describe(); //Runs c1's describe method
    c1.test_override(); //Runs Parent's method to call overriden describe method (Needs virtual on Parent class)


    printf("\n\n\n");
    c1.p_pr_describe();
    c1.p_pb_describe();
    //c1.p_priv_describe(); //Will get nothing because method is private on Parent side

    //Calling parent methods of Child1
    c1.Parent::public_describe();
    //c1.Parent::protected_describe; WILL NOT WORK because protected_describe can only be used within inherited class definition NOT object
    //c1.Parent::private_describe; WILL NOT WORK because private_describe can only be used within PARENT template class NOT object nor inherited class definition
    return 0;
}