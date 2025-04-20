#include <iostream>
#include <algorithm>
using namespace std;

void printlabel(string messages){
    cout<<"----------[ "<< messages <<" ]----------"<<endl;
}

struct worker{
    int id  = 0;
    string name;
    string gender;
    string position;
    float wage = 0;
    float hour = 0;
    float salary = 0; 

    void input()
    {
        printlabel("Input Worker Infomation");
        cout<<"Enter worker ID : "; cin>>id;
        cout<<"Enter worker Name : ";
        cin.ignore();
        getline(cin, name);
        cout<<"Enter worker Gender : "; cin>>gender;
        cout<<"Enter worker Position : ";
        cin.ignore();
        getline(cin, position);
        cout<<"Enter worker Wage : "; cin>>wage;
        cout<<"Enter worker Hour : "; cin>>hour;
    }
    
    void output()
    {
        cout<<"Enter worker ID : "<<id<<endl;
        cout<<"Enter worker Name : "<<name<<endl;
        cout<<"Enter worker Gender : "<<gender<<endl;
        cout<<"Enter worker Position : "<<position<<endl;
        cout<<"Enter worker Wage : "<<wage<<endl;
        cout<<"Enter worker Hour : "<<hour<<endl;
        workerSalary();
    }

    int workerSalary(){
        float salary = wage * hour;
        if(gender == "Male" || gender == "male"){
            salary = (salary*70)/100; 
            cout<<"Worker Salary : "<<salary<<" $"<<endl;
        }else if(gender == "Female" || gender == "female"){
            salary = (salary*75)/100; 
            cout<<"Worker Salary : "<<salary<<" $"<<endl;
        }else cout<<"Worker Salary is : "<<salary<<" $"<<endl;
        return salary;
    }
};

void initworkers(worker workerArray[])
{
    workerArray[0] = {101, "LP", "Male", "Shinigami", 700, 100};
    workerArray[1] = {102, "LP", "Male", "Shinigami", 600, 150};
    workerArray[2] = {103, "LP", "Male", "Shinigami", 300, 200};
    workerArray[3] = {104, "LP", "female", "Shinigami", 400, 50};
    workerArray[4] = {105, "LP", "Male", "Shinigami", 500, 10};
}

void printLogo()
{
    cout << " ____  __  __ ____         ____                      _      " << endl;
    cout << " / ___||  \\/  / ___|       / ___|___  _ __  ___  ___ | | ___ " << endl;
    cout << " \\___ \\| |\\/| \\___ \\ _____| |   / _ \\| '_ \\/ __|/ _ \\| |/ _ \\" << endl;
    cout << "  ___) | |  | |___) |_____| |__| (_) | | | \\__ \\ (_) | |  __/" << endl;
    cout << " |____/|_|  |_|____/       \\____\\___/|_| |_|___/\\___/|_|\\___|" << endl;
}

int PrintMainMenu(){
    printLogo();
    cout<<"\t1.Create New Worker"<<endl;
    cout<<"\t2.Edit Worker Information"<<endl;
    cout<<"\t3.Detele Worker"<<endl;
    cout<<"\t4.Search Worker"<<endl;
    cout<<"\t5.Show Worker"<<endl;
    cout<<"\t6.Exit"<<endl;

    int option;
    cout<<"Choose Option From 1->6 : "; cin>>option; 
    return option;
}

int printShowWorker(){
    cout<<"\t1.Show Worker by ID in ASC"<<endl;
    cout<<"\t2.Show worker by Salary in DES"<<endl;
    cout<<"\t3.Exit"<<endl;

    int showOption;
    cout<<"Choose Option From 1->3 : "; cin>>showOption; 
    return showOption;
}

int searchWorkerbyID(worker workerArray[], int counter){
    int workerID;
    cout<<"Enter Worker ID To search : "; cin>>workerID;

    int foundIndex = -1;
    for (int i = 0; i < counter; i++){
        if (workerID == workerArray[i].id){
            foundIndex = i;
            printlabel("Search Worker ID");
            workerArray[i].output();
        }
    }
    if (foundIndex == -1){
        cout<<"There is no record of this ID : "<<workerID<<endl;
    }
    return foundIndex;
}

void printWorker(worker workerArray[], int counter){
    for (int i = 0; i < counter; i++){
        workerArray[i].output();
        cout<<"\t___________________________"<<endl;
    }
}

void pressenter(){
    printlabel("Press Enter To Continue");
    cin.ignore();
    cin.get();
}

bool idComparator(worker work1, worker work2){
    return work1.id  < work2.id;
}
bool salaryComparator(worker work1, worker work2){
    return work1.salary  > work2.salary;
}

int main(){
    system("cls");
    int option;
    int n = 50;
    worker workerArray[n];
    int counter = 5;
    initworkers(workerArray);
    do{
        system("cls");
        option = PrintMainMenu();
        switch(option){
            case 1:
            {
                system("cls");
                workerArray[counter++].input();
                cout<<"====> Successfully Create Ner Worker!"<<endl;
            }
            break;
            case 2:
            {
                system("cls");

                pressenter();
            }
            break;
            case 3:
            {
                system("cls");
                printlabel("Delete Worker by ID");
                if (counter == 0){
                    cout<<"There is no worker data to delete!!!"<<endl;
                    break;
                }
                int foundIndex = searchWorkerbyID(workerArray, counter);
                if(foundIndex >= 0){
                    char confirmlatter;
                    cout<<"Are you sure ? Y/n : ";
                    cin>>confirmlatter;
                    if(confirmlatter == 'Y' || confirmlatter == 'y'){
                        for(int i = foundIndex; i < counter - 1; i++){
                        workerArray[i] = workerArray[i+1];
                    }
                    counter--;
                    cout<<"Worker is Delete successfully...!"<<endl;
                    }else if (confirmlatter == 'n'){
                        cout<<"Delete operation isaborted successfully!"<<endl;
                    }else {
                        cout<<"Invalid option!!, Try again!"<<endl;
                    }
                }
                pressenter();
            }
            break;
            case 4:
            {
                system("cls");
                searchWorkerbyID(workerArray, counter);
                pressenter();
            }
            break;
            case 5:
            {
                if ( counter == 0){
                    cout<<"There is no data of worker has store yet!"<<endl;
                    cout<<"Please create the worker first!"<<endl;
                    cout<<"Thank You!!!"<<endl;
                    break;
                    pressenter();
                }

                int showOption;
                showOption = printShowWorker();
                do
                {
                    switch(showOption){
                        case 1:{
                            system("cls");
                            printlabel("Show Worker ASC by ID");
                            sort(workerArray, workerArray+counter, idComparator);
                            printWorker(workerArray, counter);
                            pressenter();
                        }
                        break;
                        case 2:{
                            system("cls");
                            printlabel("Show Worker DES by Salary");
                            sort(workerArray, workerArray+counter, salaryComparator);
                            printWorker(workerArray, counter);
                            pressenter();
                        }
                        break;
                        default:
                            cout<<"Return To MainMenu!"<<endl;
                            break;
                    }
                }while (showOption != 3);
            }
            break;
                pressenter();
            default:
                cout<<"Exit From The Program!"<<endl;
                break;
            }
    }while(option != 6);

    return 0;
}