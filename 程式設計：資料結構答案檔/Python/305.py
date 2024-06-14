class Employee:
    def __init__(self, e_id, e_name, salary, d_id):
        self.e_id = e_id
        self.e_name = e_name
        self.salary = salary
        self.d_id = d_id

class Department:
    def __init__(self, d_id, d_name, m_id):
        self.d_id = d_id
        self.d_name = d_name
        self.m_id = m_id

class Project:
    def __init__(self, p_id, p_name, location):
        self.p_id = p_id
        self.p_name = p_name
        self.location = location

class HourLog:
    def __init__(self, e_id, p_id, p_hours):
        self.e_id = e_id
        self.p_id = p_id
        self.p_hours = p_hours

def getData(employees: list, departments: list, projects: list, hour_logs):
    E, D, P, H = map(int, input().split())
    for _ in range(E):
        e_id, e_name, salary, d_id = input().split()
        employees.append(Employee(e_id, e_name, int(salary), d_id))
    for _ in range(D):
        d_id, d_name, m_id = input().split()
        departments.append(Department(d_id, d_name, m_id))
    for _ in range(P):
        p_id, p_name, p_location = input().split()
        projects.append(Project(p_id, p_name, p_location))
    for _ in range(H):
        e_id, p_id, p_hours = input().split()
        hour_logs.append(HourLog(e_id, p_id, int(p_hours)))
    search_name = input()
    return search_name
        
def check(employees: list, departments: list, projects: list, hour_logs, e_name):
    hours = 0
    ans = []
    employee = [employee for employee in employees if employee.e_name == e_name]
    if employee ==None: return
    for hour_log in hour_logs:        
        if hour_log.e_id == employee[0].e_id:
            e_projects = [project for project in projects if project.p_id == hour_log.p_id]
            if e_projects:
                for project in e_projects:
                    hours += hour_log.p_hours
                    ans.append([project.p_name, hour_log.p_hours])
    f_ans = sorted(ans, key = lambda x: x[0])
    for a in f_ans:
        print(a[0], a[1])
    print(hours)                

def main():
    employees = []
    departments = []
    projects = []
    hour_logs = []   
    e_name = getData(employees, departments, projects, hour_logs)
    check(employees, departments, projects, hour_logs, e_name)    

main()