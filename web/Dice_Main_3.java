package bean.user;
public class Dice_Main_3 {
 public static void main(String [] args) {
 bean.user.Dice3 dice3 = new bean.user.Dice3();
 dice3.setStarNum(Integer.parseInt(args[0]));
 dice3.setEndNum(Integer.parseInt(args[1]));
 System.out.println(Integer.parseInt(args[0])+"과"+Integer.parseInt(args[1])+"사이 주사위 값");
 System.out.println("=" + dice3.getNum1());
 }
}