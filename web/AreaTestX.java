package bean.user;
class AreaTestX {
 float width, height, depth;
 public AreaTestX(float h){
 height = h;
 }
 public AreaTestX(float h, float w) {
 height = h;
 width = w;
 }
 public double CalArea(float a) {
 double sum1;
 sum1 = a*a*3.14;
 return sum1;
 }
 public float CalArea(float a, float b) {
 float sum2;
 sum2 = a*b;
 return sum2;
 }
}