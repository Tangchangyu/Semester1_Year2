public class Person {

    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void greet() {
        System.out.println("Hello, I am " +
                name + ", and I am " + age + " years old");
    }

    public static void main(String[] args) {
        if (args.length < 2){
            System.out.println("Please enter the name and age:");
            return;
        }

        String name = args[0];
        String ageString = args[1];
        int age = Integer.parseInt(ageString);

        Person tom = new Person(name, age);
        tom.greet();
    }
}
