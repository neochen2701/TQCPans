import java.util.*;

class Employee {
    String eId, eName;
    int salary;
    String dId;

    Employee(String eId, String eName, int salary, String dId) {
        this.eId = eId;
        this.eName = eName;
        this.salary = salary;
        this.dId = dId;
    }
}

class Department {
    String dId, dName, mId;

    Department(String dId, String dName, String mId) {
        this.dId = dId;
        this.dName = dName;
        this.mId = mId;
    }
}

class Project {
    String pId, pName, location;

    Project(String pId, String pName, String location) {
        this.pId = pId;
        this.pName = pName;
        this.location = location;
    }
}

class HourLog {
    String eId, pId;
    int pHours;

    HourLog(String eId, String pId, int pHours) {
        this.eId = eId;
        this.pId = pId;
        this.pHours = pHours;
    }
}

class ProjectParticipation implements Comparable<ProjectParticipation> {
    String pName;
    int pHours;

    ProjectParticipation(String pName, int pHours) {
        this.pName = pName;
        this.pHours = pHours;
    }

    @Override
    public int compareTo(ProjectParticipation other) {
        return this.pName.compareTo(other.pName);
    }
}

public class JPA305 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int eNum = scanner.nextInt();
        int dNum = scanner.nextInt();
        int pNum = scanner.nextInt();
        int hNum = scanner.nextInt();

        ArrayList<Employee> employees = new ArrayList<>();
        ArrayList<Department> departments = new ArrayList<>();
        ArrayList<Project> projects = new ArrayList<>();
        ArrayList<HourLog> hourLogs = new ArrayList<>();

        for (int i = 0; i < eNum; i++) {
            employees.add(new Employee(scanner.next(), scanner.next(), scanner.nextInt(), scanner.next()));
        }

        for (int i = 0; i < dNum; i++) {
            departments.add(new Department(scanner.next(), scanner.next(), scanner.next()));
        }

        for (int i = 0; i < pNum; i++) {
            projects.add(new Project(scanner.next(), scanner.next(), scanner.next()));
        }

        for (int i = 0; i < hNum; i++) {
            hourLogs.add(new HourLog(scanner.next(), scanner.next(), scanner.nextInt()));
        }

        String sName = scanner.next();
        List<ProjectParticipation> participations = new ArrayList<>();
        int totalHours = 0;

        for (HourLog hl : hourLogs) {
            for (Employee e : employees) {
                if (e.eName.equals(sName) && e.eId.equals(hl.eId)) {
                    for (Project p : projects) {
                        if (p.pId.equals(hl.pId)) {
                            participations.add(new ProjectParticipation(p.pName, hl.pHours));
                            totalHours += hl.pHours;
                        }
                    }
                }
            }
        }

        Collections.sort(participations);

        for (ProjectParticipation pp : participations) {
            System.out.println(pp.pName + " " + pp.pHours);
        }
        System.out.println(totalHours);
    }
}
