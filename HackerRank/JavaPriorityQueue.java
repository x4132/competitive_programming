package HackerRank;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;
/*
 * Create the Student and Priorities classes here.
 */

class Student {
    private int id;
    private String name;
    private double cgpa;

    Student(int id, String name, double cgpa) {
        this.id = id;
        this.name = name;
        this.cgpa = cgpa;
    }

    int getId() {
        return id;
    }

    String getName() {
        return name;
    }

    double getCGPA() {
        return cgpa;
    }
}

class Priorities {
    List<Student> getStudents(List<String> events) {
        PriorityQueue<Student> pQueue = new PriorityQueue<>(11, new StudentComparator());

        for (int i = 0; i < events.size(); i++) {
            String[] cur = events.get(i).split(" ");

            if (cur[0].equals("ENTER")) {
                pQueue.add(new Student(Integer.parseInt(cur[3]), cur[1], Double.parseDouble(cur[2])));
            } else {
                pQueue.poll();
            }
        }

        ArrayList<Student> output = new ArrayList<>();
        while (!pQueue.isEmpty()) {
            output.add(pQueue.poll());
        }

        return output;
    }
}

class StudentComparator implements Comparator<Student> {
    @Override
    public int compare(Student y, Student x) {
        if (x.getCGPA() > y.getCGPA()) {
            return 1;
        } else if (x.getCGPA() < y.getCGPA()) {
            return -1;
        } else if (x.getName().compareTo(y.getName()) == 0) {
            return x.getId() - y.getId();
        } else {
            return y.getName().compareTo(x.getName());
        }
    }
}

public class JavaPriorityQueue {
    private final static Scanner scan = new Scanner(System.in);
    private final static Priorities priorities = new Priorities();
    
    public static void main(String[] args) {
        int totalEvents = Integer.parseInt(scan.nextLine());    
        List<String> events = new ArrayList<>();
        
        while (totalEvents-- != 0) {
            String event = scan.nextLine();
            events.add(event);
        }
        
        List<Student> students = priorities.getStudents(events);
        
        if (students.isEmpty()) {
            System.out.println("EMPTY");
        } else {
            for (Student st: students) {
                System.out.println(st.getName());
            }
        }
    }
}