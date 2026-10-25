import java.util.Scanner;



public class ATM {
    Scanner scanner = new Scanner(System.in);

    private int next_operation = 0;

    private double balance;
    private  String user_name;
    private int password;

    public ATM(double balance, String usrName,int password){
        this.balance = balance;
        this.user_name = usrName;
        this.password = password;   //Creat an account;
        surface();

    }
    public void surface(){
        while (next_operation !=4)

       {     System.out.println("\n---\nPlease select your transaction: \n1.Deposit \n2.Withdraw \n3.Query Balance\n4.Exit");
            next_operation = scanner.nextInt(); //读取下一个操作



            //异常操作数处理
            if (next_operation<= 0 || next_operation>4){
                System.out.println("The wrong number , please select again:");
                next_operation = 0;
            }

            switch (next_operation) {
                case 0:
                    break;

                case 1:
                    DepositMoney();
                    break;

                case 2:
                    WithdrawMoney();
                    break;

                case 3:
                    QueryBalance();
                    break;

                case 4:
                    return ;

                default:
                    break;
            }//下一步操作
        
        }

    }

    public void DepositMoney(){
        System.out.println("How much money do you want to DEPOSIT?\n");
        double money_to_deposit = scanner.nextDouble();

        if(money_to_deposit <=0){
            System.out.println("Invalid number.\n");
            return ;
        }

        else {
            balance += money_to_deposit;
            System.out.println("Successful deposit.\nNow you balance is :");
            System.out.print(balance);
            return ;
        }
    }

    public void WithdrawMoney(){
        System.out.println("How much money do you want to WITHDRAW?\n");
        double money_to_withdraw = scanner.nextDouble();

        //输入值校验
        if (money_to_withdraw <= 0){
            System.out.println("Invalid number.\n");
            return ;
        }

        
        System.out.println("enter yout password");


      
{
        if(money_to_withdraw > balance){
            System.out.println("Balance is not enough.\n");
            return ;
        }

        else {
            balance -= money_to_withdraw;
            System.out.println("Successs withdrawal!\n");
            return ;
        }
    }

    }

    public void QueryBalance(){
        System.out.println("Your balance is:");
        System.out.print(balance);
        return ;
    }

    public static void main(String args[]){
        ATM account = new ATM(10000, "name", 0);
        account.surface();
    }
}
