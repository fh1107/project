package bean.user;
 class AreaTest2 {
 private float width,height;
 public AreaTest2(){
 }
 public AreaTest2(float width, float height) {
 this.width = width; this.height = height;
 }
 public void setWidth(float width){
 this.width = width;
 }
 public void setHeight(float height){
 this.height = height;
 }
 public float getWidth(){
 return this.width;
 }
 public float getHeight() {
 return this.height;
 }
 public float calArea(float a, float b){
 float sum = a+ b;
 return sum;
 }
 }
