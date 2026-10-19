

public class Student {
    private String id;
    private String name;
    private int  gender;

    private String Class;

    public Student(String id, String name, int gender){
        this.id = id;
        this.name = name;
        this.gender = gender;
    }

    public void greet()[
        System.out.println("Hello I'm "+ name +". I am a " +(gender==1?"male":"female")+" student, and I am from Class"+Class );
    ]
}
