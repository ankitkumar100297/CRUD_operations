#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>

using namespace std;

void View(){
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.0.106", "admin", "admin", "tsf", 0, NULL, 0);

    if(conn){
            cout<< "connected"<< endl;
        int qstate = mysql_query(conn, "select * from test");

        if(!qstate){
            res = mysql_store_result(conn);
            while((row = mysql_fetch_row(res)))
            {
                cout<< "id :"<<row[0]<<endl<< "name :"<<row[1]<<endl<< "location :"<<row[2]<<endl;
            }
        }
    }
}

void Update(){
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.0.106", "admin", "admin", "tsf", 0, NULL, 0);

    int qstate=0,id;

    string Location,name;

    cout<<"Enter the id you want to update"<<endl;
    cin>>id;

    cout<<"Enter its new name"<<endl;
    cin>>name;

    stringstream ss;
    ss<< "UPDATE test SET name = ' "<< name << " 'WHERE id= '"<< id << "'";


    string query =  ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "RECORD UPDATED" << endl;
        }else{
            cout<<"failed"<<endl;
        }

}
void Delete(){
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.0.106", "admin", "admin", "tsf", 0, NULL, 0);

    int qstate=0,id;

    cout<<"Enter the Id number you want to delete"<<endl;
    cin>>id;

    stringstream ss;
    ss<< "DELETE FROM test WHERE id ="<<id;
    string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "RECORD DELETED" << endl;
        }else{
            cout<<"failed"<<endl;
        }

}
void Insert(){
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.0.106", "admin", "admin", "tsf", 0, NULL, 0);
    int qstate = 0,Id;
    string Name,Location;

    cout<<"Enter Id"<<endl;
    cin>>Id;


    cout<<"Enter Name"<<endl;
    cin>>Name;

    cout<<"Enter Location"<<endl;
    cin>>Location;
    stringstream ss;
    ss << "INSERT INTO test(Id,Name,Location) VALUES('" << Id << "','" << Name << "','" << Location << "')";
    cout<<endl<<endl<<endl;

    string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "RECORD INSERTED" << endl;
        }else{
            cout<<"failed"<<endl;
        }
}

int main()
{
    int ans;
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"192.168.0.106", "admin", "admin", "tsf", 0, NULL, 0);
    if(conn){
        cout<<"Connected,conn="<<conn<<endl;
    }
    else {
        cout<<"Not connected"<<endl;
    }


    cout<< endl << endl << "---------------" << endl << endl << "1. Insert Record" << endl << "2. Delete Record" << endl << "3. Update Record" << endl << "4. View Record" << endl << endl << endl << "---------------" << endl;
    cout<<"Your Answer :"<<endl;

    cin>>ans;
    switch(ans){
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Update();
            break;
        case 4:
            View();
        }

}
