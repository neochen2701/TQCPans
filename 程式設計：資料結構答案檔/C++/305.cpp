#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define SIZE 20

using namespace std;

struct Employee {
    char e_id[SIZE];
    char e_name[SIZE];
    int salary;
    char d_id[SIZE];
};

struct Department {
    char d_id[SIZE];
    char d_name[SIZE];
    char m_id[SIZE];
};

struct Project {
    char p_id[SIZE];
    char p_name[SIZE];
    char location[SIZE];
};

struct HourLog {
    char e_id[SIZE];
    char p_id[SIZE];
    int p_hours;
};

struct Num {
    int e_num;
    int d_num;
    int p_num;
    int h_num;
};

struct ANS {
    char p_name[SIZE];
    int p_hours;
};

void getData(vector<Employee>& e, vector<Department>& d, vector<Project>& p, vector<HourLog>& h, Num& np) {
    cin >> np.e_num >> np.d_num >> np.p_num >> np.h_num;
    e.resize(np.e_num);
    d.resize(np.d_num);
    p.resize(np.p_num);
    h.resize(np.h_num);
    for (int i = 0; i < np.e_num; i++)
        cin >> e[i].e_id >> e[i].e_name >> e[i].salary >> e[i].d_id;
    for (int i = 0; i < np.d_num; i++)
        cin >> d[i].d_id >> d[i].d_name >> d[i].m_id;
    for (int i = 0; i < np.p_num; i++)
        cin >> p[i].p_id >> p[i].p_name >> p[i].location;
    for (int i = 0; i < np.h_num; i++)
        cin >> h[i].e_id >> h[i].p_id >> h[i].p_hours;
}

int getEmployeeIndex(const string& s_name, const vector<Employee>& employees) {
    for (int i = 0; i < employees.size(); i++)
        if (strcmp(employees[i].e_name, s_name.c_str()) == 0)
            return i;
    return -1; // In case employee is not found
}

int compareName(const void* a, const void* b) {
    const ANS* p1 = static_cast<const ANS*>(a);
    const ANS* p2 = static_cast<const ANS*>(b);
    return strcmp(p1->p_name, p2->p_name);
}

void printAns(const vector<ANS>& ans) {
    for (const auto& a : ans) {
        cout << a.p_name << " " << a.p_hours << endl;
    }
}

void searchData(const char* e_id, const vector<Project>& p, const vector<HourLog>& h, const Num& num) {
    int hours = 0;
    vector<ANS> ans;
    for (const auto& hl : h) {
        if (strcmp(hl.e_id, e_id) == 0) {
            for (const auto& proj : p) {
                if (strcmp(hl.p_id, proj.p_id) == 0) {
                    ANS a;
                    strcpy(a.p_name, proj.p_name);
                    a.p_hours = hl.p_hours;
                    ans.push_back(a);
                    hours += hl.p_hours;
                    break;
                }
            }
        }
    }
    sort(ans.begin(), ans.end(), [](const ANS& a, const ANS& b) -> bool {
        return strcmp(a.p_name, b.p_name) < 0;
    });
    printAns(ans);
    cout << hours << endl;
}

int main() {
    vector<Employee> employees;
    vector<Department> departments;
    vector<Project> projects;
    vector<HourLog> hourLogs;
    Num num;
    string s_name;
    getData(employees, departments, projects, hourLogs, num);
    cin >> s_name;
    int e_index = getEmployeeIndex(s_name, employees);
    if (e_index != -1) {
        searchData(employees[e_index].e_id, projects, hourLogs, num);
    }
    return 0;
}
