package bean.user;
import bean.user.AreaTest;
 class AreaExam {
 public static void main(String [] args) {
 float sum1, sum2, x, y;
 x = Float.parseFloat(args[0]); y = Float.parseFloat(args[1]);
 AreaTest areaTest1 = new AreaTest();
 sum1 = areaTest1.calArea(x,y);
 System.out.println("입력한 값의 합1은 " + sum1 +"입니다.");
 AreaTest areaTest2 = new AreaTest(10.3f,13.4f);
 sum2 = areaTest2.calArea(areaTest2.width,areaTest2.height);
 System.out.println("입력한 값의 합2는 " + sum2 + "입니다.");
 }
 }
 