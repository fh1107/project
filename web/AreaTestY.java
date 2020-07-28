package bean.user;

class AreaTestY extends AreaTestX implements AreaCal, CircleCal{
 public AreaTestY(float h, float w, float d) {
 super(h,w);
 depth = d;
 }
 public float CalArea(float a, float b, float c ) {
 float sum3;
 sum3 = (a * b) *c;
 return sum3;
 }
 public float rtcal(float a, float b) {
 float rtarea;
 rtarea = a*b;
 System.out.println("인터페이스에 의한 사각형면적은 " +rtarea + "입니다");
 return rtarea;
 }
 public float rhcal(float a, float b) {
 float rharea;
 rharea = a*b/2;
 System.out.println("인터페이스에 의한 마름모 면적은 " + rharea + "입니다.");
 return rharea;
 }
 public double cccal(float a) {
 double ccarea;
 ccarea = a * a * 3.14;
 System.out.println("인터페이스에 의한 원면적은 " +ccarea + "입니다.");
 return ccarea;
 }
 }
 