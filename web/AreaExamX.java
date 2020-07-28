package bean.user;

 class AreaExamX {
 public static void main(String args[]) {
 double sum ;
 float x,y,z;
 x = Float.parseFloat(args[0]);
 y = Float.parseFloat(args[1]);
 z = Float.parseFloat(args[2]);
 
 AreaTestX object1 = new AreaTestX(x);
 sum = object1.CalArea(x);
 System.out.println("원 면적은 " +sum + "입니다.");
 
 AreaTestX object2 = new AreaTestX(x,y);
 sum = object2.CalArea(x,y);
 System.out.println("직사각형 면적은 " +sum + "입니다.");
 
 AreaTestY object3 = new AreaTestY(x,y,z);
 sum = object3.CalArea(x,y,z);
 System.out.println("부피는 " + sum + "입니다.");
 object3.rtcal(x,y);
 object3.rhcal(x,y);
 object3.cccal(x);
 }
}