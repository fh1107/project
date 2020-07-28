package bean.user;
public class DbLogin {
 private String userName;
 private String userPasswd;
 private boolean logStatus;
 public void setUserName(String userName) {
   this.userName = userName.trim(); 
  }
  public String getUserName() {
     return this.userName;
  }
  public void setUserPasswd(String userPasswd) {
    this.userPasswd = userPasswd.trim();
  }
  public String getUserPasswd() {
    return this.userPasswd;
  }
  public void setLogStatus(boolean logStatus) {
    this.logStatus = logStatus;
  }
  public boolean isLogStatus() {
    return this.logStatus;
  }
}  
	