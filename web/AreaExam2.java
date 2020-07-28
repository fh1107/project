package bean.user;
import bean.user.AreaTest2;
class AreaExam2{
 public static void main(String [] args){
 float sum1, sum2, x, y;
 x = Float.parseFloat(args[0]);
 y = Float.parseFloat(args[1]);
 AreaTest2 areaTestA = new AreaTest2();
 sum1 = areaTestA.calArea(x,y);
 System.out.println("입력한 값의 합1은 " +sum1 + "입니다.");
 AreaTest2 areaTestB = new AreaTest2(10.3f,13.4f);
 sum2 = areaTestB.calArea(areaTestB.getWidth(),areaTestB.getHeight());
 System.out.println("입력한 값의 합2는 " + sum2 + "입니다.");
 }
 }