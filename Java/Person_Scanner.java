import java.util.Scanner;


public class Person_Scanner {
    private String name;
    private int age;

    public Person_Scanner(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void greet() {
        System.out.println("Hello, I am " +
                name + ", and I am " + age + " years old");
    }

    public static void main(String args[]){
        // 创建scanner对象
        Scanner scanner = new Scanner(System.in);

        System.out.println("请输入姓名：");
        String name = scanner.nextLine();

        System.out.println("请输入年龄：");
        int age = scanner.nextInt();

        Person_Scanner person = new Person_Scanner(name, age);
        person.greet();
    }
}
