package bean.user;
public class Login {
  private String userName;
  private String userPasswd;
  public void setUserName(String userName) {
   this.userName = userName.trim();
  }
  public String getUserName() {
   return this.userName;
  }
  public void setUserPasswd (String userPasswd) {
	  this.userPasswd = userPasswd.trim();
  }
  public String getUserPasswd () {
	 return this.userPasswd;
  }
 }  
   