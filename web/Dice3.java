package bean.user;
import java.util.*;
public class Dice3{
  private int num1;
  private int num2;
  private int maxNum;
  private int starNum;
  private int endNum;
  private int minNum;
  public void setStarNum(int starNum) {
  this.starNum = starNum;
  }
  
  public int getStarNum() {
  return starNum;
  }
  
  public void setEndNum(int endNum) {
  this.endNum = endNum;
  }
  public int getEndNum() {
  return endNum;
  }
  public int getNum1() {
  num1 = (int)(Math.random()*(endNum-starNum))+ starNum;
  return num1;
  }
  public int getNum2() {
  num2 = (int)(Math.random()*(endNum-starNum))+ starNum;
  return num2;
  }
  public int getmaxNum() {
    num1 = getNum1(); 
	num2 = getNum2();
   if(num1 > num2) {
	  maxNum = num1; 
    return maxNum;
	}
	else if(num2 > num1) {
	maxNum = num2;
     return maxNum;
    }
    else {
	maxNum = num1;
    return maxNum;
    }	
 }
  public int getminNum() {
	num1 = getNum1(); 
	num2 = getNum2();
   if(num1 > num2) { 
	minNum = num2;
	return minNum;
	}
	else if(num2 > num1) {
     minNum = num1;
	return minNum;
    }
    else {
    minNum = num1;
	return minNum;
    }	
 }
}