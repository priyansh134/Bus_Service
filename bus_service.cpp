#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define M INT_MAX
vector<string> city={"Delhi", "Noida", "Gurgaon", "Chandigarh"};
// 0-4: Delhi, 5-9:Noida, 10-12:Gurgaon, 13-16:Chandigarh
vector<string> areas={ "ITO", "Rajiv Chowk", "India Gate", "Cannaught Place",
"IGI",
"Sector 62", "Sector 128", "Noida Stadium",
"ISKCON", "DLF Mall",
"Ambience Mall", "Sultanpur National Park", "DLF Cyber Hub",
"Rose Garden", "Sukhna Lake", "MC Zoological Park",
"Elante Mall"
};
vector<vector<int>> path={
{0, 3, M, 2, 10, M, M, M, M, M, M, M, M, M, M, M, M},
{3, 0, M, 5, M, 10, 20, M, M, M, M, M, M, M, M, M, M},
{M, M, 0, M, 7, M, M, M, 18, M, M, M, 7, M, M, M, M},
{2, 5, M, 0, 1, M, M, M, M, M, 10, M, M, M, M, M, M},
{10, M, 7, 1, 0, M, M, M, M, M, M, M, M, M, 50, M, M},
{M, 10, M, M, M, 0, 5, M, 9, M, M, M, M, M, M, M, M},
{M, 20, M, M, M, 5, 0, 2, M, 3, M, M, M, M, 70, M, M},
{M, M, M, M, M, M, 2, 0, M, M, M, M, M, M, M, M, M},
{M, M, 18, M, M, 9, M, M, 0, M, M, M, M, M, M, M, M},
{M, M, M, M, M, M, 3, M, M, 0, M, 28, M, M, M, M, M},
{M, M, M, 10, M, M, M, M, M, M, 0, M, 3, M, M, 30, M},
{M, M, M, M, M, M, M, M, M, 28, M, 0, 1, M, M, M, M},
{M, M, 7, M, M, M, M, M, M, M, 3, 1, 0, M, M, M, M},
{M, M, M, M, M, M, M, M, M, M, M, M, M, 0, 1, 8, M},
{M, M, M, M, 50, M, 70, M, M, M, M, M, M, 1, 0, M, 5},
{M, M, M, M, M, M, M, M, M, M, 30, M, M, 8, M, 0, 6},
{M, M, M, M, M, M, M, M, M, M, M, M, M, M, 5, 6, 0}
};
void FloydWarshall() {
for (int k=0;k<16;k++) {
for (int i=0;i<16;i++) {
for (int j=0;j<16;j++) {
if (path[i][j]>(path[i][k]+path[k][j]) && (path[k][j]!=M && path[i][k]!=M)) {
path[i][j]=path[i][k]+path[k][j];
}
}
}
}
}
/* ------------------------------------------- */
struct trip {
int start,end,price,bus_type;
string company_name,bus_id;
};
struct bus {
int index,bus_status,start,end;
char company[100],bus_id[40];
};
class Admin {
string user_id,pass;
public:
bus ob[20];
Admin() {
user_id="admin";
pass="test";
}
void login();
void change_password();
void bus_details();
void add_new_bus();
void delete_bus();
};
class User {
string name,email,crt_pass,mobile,gender;
int start,end,bus_type,trip_cost,bus_stat;
vector<trip> t;
public:
User() {
email="user";
crt_pass="test";
}
void login();
void signup();
void change_password();
void book_trip();
void book_tour();
void trip_details();
void trip_history();
};
User USR;
Admin ADM;
int noofbus=5,del=20;
void user_menu();
void admin_menu();
void heapify(bus A[], int n, int i) {
int mx = i;
int l = 2*i + 1;
int r = 2*i + 2;
if (l<n && A[l].bus_status<A[mx].bus_status) mx = l;
if (r<n && A[r].bus_status<A[mx].bus_status) mx = r;
if (mx != i) {
swap(A[i].bus_status, A[mx].bus_status);
heapify(A, n, mx);
}
}
void HeapSort(bus A[], int n) {
for (int i=n/2-1;i>=0;i--) {
heapify(A, n, i);
}
for (int i=n-1;i>0;i--) {
swap(A[0], A[i]);
heapify(A, i, 0);
}
}
bool cmp(const bus &a, const bus &b) {
return a.bus_status>b.bus_status;
}
int allocation(int pick) {
if (ADM.ob[pick-1].bus_status) {
ADM.ob[pick-1].bus_status=0;
return 1;
}
else {
HeapSort(ADM.ob,20);
cout<<endl;
if (ADM.ob[0].bus_status==0) {
return -1; // none available
}
return 0;
}
}
/* ------------------------------ ADMIN ------------------------------ */
void Admin::login() {
system("cls");
string username,password;
while (1) {
cout<<"Enter Username: ";
cin>>username;
cout<<"Enter password: ";
cin>>password;
if (user_id==username && pass==password) {
system("cls");
cout<<"\n\n\t\tLOGGED IN SUCCESSFULLY\n\t\t\tWELCOME\n\n\n";
usleep(3000000);
system("cls");
admin_menu();
break;
}
else {
cout<<"Enter correct username and password\nPlease try again\n";
}
}
}
void Admin::change_password() {
system("cls");
string new_pass,confirm_pass;
while (1) {
cout<<"Enter new password: ";
cin>>new_pass;
cout<<"Confirm password: ";
cin>>confirm_pass;
if (new_pass==confirm_pass) {
pass=new_pass;
cout<<"Changed password successfully.\n";
break;
}
else {
cout<<"Passwords did not match, please enter new password and confirm it.\n";
}
}
}
void Admin::bus_details() {
system("cls");
cout<<"----------------"<<noofbus<<" Buses Found----------------\n";
for (int i=0;i<noofbus;i++) {
cout<<"Company Name: "<<ADM.ob[i].company<<endl;
cout<<"Bus ID: "<<ADM.ob[i].bus_id<<endl;
cout<<"Bus Availability: "<<ADM.ob[i].bus_status<<endl;
if (i!=noofbus-1) cout<<endl;
}
cout<<"--------------------------------------------\n";
usleep(8000000);
system("cls");
}
void Admin::add_new_bus() {
system("cls");
bus B;
cout<<"Enter company Name: ";
cin>>B.company; cin.clear();
cout<<"Enter BUS ID: ";
cin>>B.bus_id; cin.clear();
B.bus_status=1;
ob[noofbus++]=B;
system("cls");
cout<<"Bus added Successfully.\n";
usleep(4000000);
system("cls");
}
void Admin::delete_bus() {
system("cls");
int n;
for (int i=0;i<noofbus;i++) {
cout<<ADM.ob[i].index<<" "<<ADM.ob[i].company<<endl;
}
cout<<"Enter Index of Bus Company to delete: ";
cin>>n;
if (n>=1 && n<=noofbus) {
system("cls");
cout<<"Removed "<<ADM.ob[n-1].company<<" from Service.\n";
ADM.ob[n].bus_status=0;
sort(ADM.ob,ADM.ob+20,cmp);
noofbus--; del--;
usleep(4000000);
system("cls");
}
else {
cout<<"Please Enter valid Index for deletion.\n";
}
}
/* ------------------------------ ADMIN ------------------------------ */
/* ------------------------------ USER ------------------------------ */
void User::login() {
int c=0;
string username,password;
system("cls");
cout<<"\tLOGIN\n";
while (1) {
cout<<"Enter Email: ";
cin>>username;
cout<<"Enter password: ";
cin>>password;
ifstream input("records.txt");
while(input>>email>>crt_pass){
if(email==username && crt_pass==password){
c=1;
system("cls");
}
}
input.close();
if(c==1){
cout<<"\n\n\t\tLOGGED IN SUCCESSFULLY\n\t\t\tWELCOME\n\n\n";
usleep(3000000);
system("cls");
user_menu();
break;
}
else {
cout<<"Enter correct username and password\nPlease try again\n";
}
}
}
void User::signup() {
string pass;
system("cls");
while (1) {
cout<<"Enter your Name: ";
cin>>name;
cout<<"Enter email: ";
cin>>email;
cout<<"Enter Mobile No.: ";
cin>>mobile;
cout<<"Enter your gender(M/F): ";
cin>>gender;
cout<<"Enter password: ";
cin>>pass;
cout<<"Confirm password: ";
cin>>crt_pass;
if (pass==crt_pass) {
ofstream f1("records.txt", ios::app);
f1<<email<<' '<<crt_pass<<endl;
system("cls");
cout<<"\n\n\t\tSIGNED UP SUCCESSFULLY\n\n";
usleep(3000000);
system("cls");
login();
}
else {
cout<<"Passwords did not match.\nPlease confirm the password correctly.\n";
}
}
}
void User::change_password() {
string pass;
system("cls");
while (1){
cout<<"Enter new password: ";
cin>>pass;
cout<<"Confirm new password: ";
cin>>crt_pass;
if (pass==crt_pass) {
ofstream f1("records.txt", ios::app);
f1<<email<<' '<<crt_pass<<endl;
system("cls");
cout<<"\n\n\t\tPassword changed successfully\n\n";
usleep(3000000);
system("cls");
login();
}
else {
cout<<"Passwords did not match.\nPlease confirm the password correctly.\n";
}
}
}
void User::book_trip() {
system("cls");
int city1,city2,a1,a2,p1,p2;
cout<<"Pick city to begin journey with:\n";
for (int i=0;i<4;i++) cout<<i+1<<". "<<city[i]<<endl;
cin>>city1;
while (city1>4 || city1<1) {
cout<<"Please enter valid city.\n";
cin>>city1;
}
system("cls");
city1--;
if (city1==0) a1=0,a2=4;
else if (city1==1) a1=5,a2=9;
else if (city1==2) a1=10,a2=12;
else a1=13,a2=16;
cout<<"Enter Pickup point in "<<city[city1]<<":\n";
for (int i=a1;i<=a2;i++) cout<<i-a1+1<<". "<<areas[i]<<endl;
cin>>p1;
while (p1<1 || p1>a2-a1+1) {
cout<<"Please enter valid area.\n";
cin>>p1;
}
p1=a1+p1-1;
system("cls");
cout<<"Pick city to end journey with:\n";
for (int i=0;i<4;i++) cout<<i+1<<". "<<city[i]<<endl;
cin>>city2;
while (city2>4 || city2<1) {
cout<<"Please enter valid city.\n";
cin>>city2;
}
system("cls");
city2--;
if (city2==0) a1=0,a2=4;
else if (city2==1) a1=5,a2=9;
else if (city2==2) a1=10,a2=12;
else a1=13,a2=16;
cout<<"Enter Pickup point in "<<city[city2]<<":\n";
for (int i=a1;i<=a2;i++) cout<<i-a1+1<<". "<<areas[i]<<endl;
cin>>p2;
while (p2>a2-a1+1 || p2<1) {
cout<<"Please enter valid area.\n";
cin>>p2;
}
p2=a1+p2-1;
system("cls");
int which_comp;
cout<<"Enter which bus company to choose:\n";
for (int i=0;i<noofbus;i++) cout<<i+1<<". "<<ADM.ob[i].company<<endl;
cin>>which_comp;
int found=allocation(which_comp);
if (found==-1) {
system("cls");
cout<<"All buses are currently on a trip. We are sorry for the inconvenience.\nPlease Try again later\n";
usleep(4000000);
return;
}
else if (found) {
cout<<"Bravo! Your Bus is booked.\n";
}
else {
system("cls");
cout<<ADM.ob[which_comp-1].company<<" is already on a trip.\nPlease consider booking another company.\n";
usleep(6000000);
system("cls");
return;
}
system("cls");
int dist=path[p1][p2];
cout<<"Shortest distance between "<<areas[p1]<<" and "<<areas[p2]<<" is of "<<dist<<"kms"<<endl;
cout<<"Cost of the trip will be Rs."<<dist*5<<endl;
char conf;
cout<<"Would you like to confirm [Y/N]: ";
cin>>conf;
if (conf=='Y' || conf=='y') {
ADM.ob[which_comp-1].start=p1;
ADM.ob[which_comp-1].end=p2;
trip tmp;
tmp.bus_id=ADM.ob[which_comp-1].bus_id;
tmp.company_name=ADM.ob[which_comp-1].company;
tmp.start=p1;
tmp.end=p2;
tmp.bus_type=0;
tmp.price=dist*5;
t.push_back(tmp);
system("cls");
cout<<"Your Trip has been Set and Confirmed. Please enjoy!\n";
usleep(5000000);
system("pause");
}
else {
string fdbk;
system("cls");
cout<<"Is there any issue you encountered? Please provide your valuable feedback :)\n";
cout<<"Enter your Feedback here: ";
cin>>fdbk;
}
system("cls");
}
void User::book_tour() {
system("cls");
int origin=0,destination=0,total=0;
for (int i=0;i<17;i++) {
if (i==0) cout<<"Delhi:-\n";
else if (i==5) cout<<"Noida:-\n";
else if (i==10) cout<<"Gurgaon:-\n";
else if (i==13) cout<<"Chandigarh:-\n";
cout<<" "<<i+1<<". "<<areas[i]<<endl;
}
cout<<"Pick a city to start your Tour with: ";
cin>>origin;
while (origin<1 || origin>17) {
cout<<"Enter valid choice: "; cin>>origin;
}
origin--;
cout<<"Enter number of places you want to visit (entering more than 8 places will cost 20% more): ";
cin>>total;
vector<int> place(total);
cout<<"Enter all places you want to visit: ";
for (auto &i:place) {
cin>>i; i--;
}
cout<<"Pick a city to end you Tour with: ";
cin>>destination;
while (destination<1 || destination>17) {
cout<<"Enter valid choice: "; cin>>destination;
}
destination--;
system("cls");
int which_comp;
cout<<"Enter which bus company to choose:\n";
for (int i=0;i<noofbus;i++) cout<<i+1<<". "<<ADM.ob[i].company<<endl;
cin>>which_comp;
int found=allocation(which_comp);
if (found==-1) {
system("cls");
cout<<"All buses are currently on a trip. We are sorry for the inconvenience.\nPlease Try again later\n";
usleep(4000000);
return;
}
else if (found) {
cout<<"Bravo! Your Bus is booked.\n";
}
else {
system("cls");
cout<<ADM.ob[which_comp-1].company<<" is already on a trip.\nPlease consider booking another company.\n";
usleep(6000000);
system("cls");
return;
}
system("cls");
sort(place.begin(),place.end());
int shortestDist=INT_MAX;
vector<int> shortestPath;
do {
int dist=path[origin][place[0]]+path[place[total-1]][destination];
for (int i=0;i<total-1;i++) dist+=path[place[i]][place[i+1]];
if (dist<shortestDist) {
shortestDist=dist;
shortestPath=place;
}
} while (next_permutation(place.begin(),place.end()));
cout<<"Shortest Path for your Tour will be:\n";
cout<<"\n\t"<<areas[origin]<<" -> ";
for (int i=0;i<total;i++) cout<<areas[shortestPath[i]]<<" -> ";
cout<<areas[destination]<<endl<<endl;
cout<<"Total distance: "<<shortestDist<<" kms\n";
cout<<"Cost of Tour: Rs."<<((total>8) ? shortestDist*10*(1.20) : shortestDist*10)<<endl;
char conf;
cout<<"Would you like to confirm [Y/N]: ";
cin>>conf;
if (conf=='Y' || conf=='y') {
ADM.ob[which_comp-1].start=origin;
ADM.ob[which_comp-1].end=destination;
trip tmp;
tmp.bus_id=ADM.ob[which_comp-1].bus_id;
tmp.company_name=ADM.ob[which_comp-1].company;
tmp.start=origin;
tmp.end=destination;
tmp.bus_type=1;
tmp.price=(total>8) ? shortestDist*10*(1.20) : shortestDist*10;
t.push_back(tmp);
system("cls");
cout<<"Your Trip has been Set and Confirmed. Please enjoy!\n";
usleep(5000000);
}
else {
string fdbk;
cout<<"Is there any issue you encountered? Please provide your valuable feedback :)\n";
cout<<"Enter your Feedback here: ";
cin>>fdbk;
}
system("cls");
}
void User::trip_details() {
system("cls");
if (t.empty()) {
cout<<"Oops! No past bookings found.\n";
usleep(4000000);
return;
}
int i=t.size()-1,var;
cout<<"----------------DETAILS OF LAST TRIP----------------\n";
cout<<"Bus Company and Bus ID: "<<t[i].company_name<<" "<<t[i].bus_id<<endl;
cout<<"Start Place: "<<areas[t[i].start]<<endl;
cout<<"End Point: "<<areas[t[i].end]<<endl;
cout<<"Trip or Tour: "<<(t[i].bus_type ? "Tour" : "Trip")<<endl;
cout<<"Cost of Trip: Rs."<<t[i].price<<endl;
cout<<"----------------------------------------------------\n";
usleep(7000000);
system("cls");
}
void User::trip_history() {
system("cls");
if (t.empty()) {
cout<<"Oops! No past bookings found.\n";
usleep(5000000);
return;
}
cout<<"-------------------"<<t.size()<<" Entries Found-------------------\n";
for (int i=0;i<t.size();i++) {
cout<<"Trip number: "<<i+1<<endl;
cout<<"Bus Company and Bus ID: "<<t[i].company_name<<" "<<t[i].bus_id<<endl;
cout<<"Start Place: "<<areas[t[i].start]<<endl;
cout<<"End Point: "<<areas[t[i].end]<<endl;
cout<<"Public or Private: "<<(t[i].bus_type ? "Private" : "Public")<<endl;
cout<<"Cost of Trip: Rs."<<t[i].price<<endl;
if (i!=t.size()-1) cout<<endl;
}
cout<<"-----------------------------------------------------\n";
usleep(8000000);
system("cls");
}
/* ------------------------------ USER ------------------------------ */
/* ****************************************************************** */
void user_menu() {
int ch=0;
while (ch!=6) {
cout<<"\tOPTIONS\n";
cout<<"1. Change Password\n";
cout<<"2. Book Trip\n";
cout<<"3. Book Tour\n";
cout<<"4. Fetch Last Trip Details\n";
cout<<"5. Fetch all Trips Details\n";
cout<<"6. Exit\n";
cout<<"Enter your choice: ";
cin>>ch;
while (ch>6 || ch<0) {
cout<<"Please Enter valid choice.\n"; cin>>ch;
}
switch(ch) {
case 1:
USR.change_password();
USR.login();
break;
case 2:
USR.book_trip();
break;
case 3:
USR.book_tour();
break;
case 4:
USR.trip_details();
break;
case 5:
USR.trip_history();
break;
default:
cout<<"Thank You for using Red-Bus!\n";
break;
}
}
}
void admin_menu() {
int ch=0;
while (ch!=5) {
cout<<"\tOPTIONS\n";
cout<<"1. Change Password\n";
cout<<"2. Fetch All active Bus details\n";
cout<<"3. Add new Bus in Service\n";
cout<<"4. Delete Bus from Service\n";
cout<<"5. Exit\n";
cout<<"Enter your choice: ";
cin>>ch;
while (ch<0 || ch>5) {
cout<<"Please Enter valid choice.\n"; cin>>ch;
}
switch(ch) {
case 1:
ADM.change_password();
ADM.login();
break;
case 2:
ADM.bus_details();
break;
case 3:
ADM.add_new_bus();
break;
case 4:
ADM.delete_bus();
break;
default:
cout<<"Thank You for using Red-Bus!\n";
break;
}
}
}
void read_record() {
for (int i=0;i<5;i++) ADM.ob[i].index=i+1;
strcpy(ADM.ob[0].company,"Shree Ram Travels"); strcpy(ADM.ob[0].bus_id,"UP16BC5555");
ADM.ob[0].bus_status=1;
strcpy(ADM.ob[1].company,"Leo Travels"); strcpy(ADM.ob[1].bus_id,"DL05OK1234");
ADM.ob[1].bus_status=1;
strcpy(ADM.ob[2].company,"Shatabdi Travels"); strcpy(ADM.ob[2].bus_id,"UP14AO1352");
ADM.ob[2].bus_status=1;
strcpy(ADM.ob[3].company,"Define Travels"); strcpy(ADM.ob[3].bus_id,"DL11CW1738");
ADM.ob[3].bus_status=1;
strcpy(ADM.ob[4].company,"Yadav Ji Travels"); strcpy(ADM.ob[4].bus_id,"UP16GUJJAR");
ADM.ob[4].bus_status=1;
}
int main() {
read_record();
FloydWarshall();
system("pause");
int choice=0;
cout<<"-----RED-BUS-----\n";
cout<<" 1. User SignIn\n";
cout<<" 2. User SignUp\n";
cout<<" 3. Admin Signin\n";
cout<<" 4. Exit\n";
cout<<"Enter your choice: ";
cin>>choice;
switch(choice) {
case 1:
{
USR.login();
break;
}
case 2:
{
USR.signup();
break;
}
case 3:
{
ADM.login();
break;
}
default:
{
cout<<"Thank You for using Red-Bus!\n";
// system("pause");
break;
}
}
return 0;
}
