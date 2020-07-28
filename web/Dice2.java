package bean.user;
import java.util.*;
public class Dice2{
  private int num;
  private int starNum;
  private int endNum;
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
  public int getNum() {
  num = (int)(Math.random()*(endNum-starNum))+ starNum;
  return num;
  }
 }