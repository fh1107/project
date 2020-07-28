<%@ page language="java" contentType="text/html;charset=utf-8" pageEncoding="utf-8"%>
<% request.setCharacterEncoding("utf-8");%>
<%!
boolean isSessionOn(String str)
{
if((str==null)||str.equals("")) return false;
return true;
}
%>
<!DOCTYPE html><!--slogin2.jsp-->
<html>
<head>
<meta charset="utf-8">
<title>로그인 처리</title>
</head>
<body>
<%if(!isSessionOn(request.getParameter("user_id"))
|| !isSessionOn(request.getParameter("user_password")))
{
out.println("<p>정확히 입력하세요.</p>");
out.println("<p><a href=\"slogin.html\">로그인하기</a></p>");
return;
}
//아이디와 비밀번호 admin으로 설정 --추후에 DB에서 가져옴//
String userId="admin";
String userPassword="admin";
//아이디 오류
if(request.getParameter("user_id").equals(userId)&&
request.getParameter("user_password").equals(userPassword))
{
   out.println("<p>로그인 성공</p>");
   out.println("<p><a href=\"suser1.jsp\">회원 페이지1</a></p>");
   //세션 변수 및 값 설정
   session.setAttribute("sid",request.getParameter("user_id"));
   session.setAttribute("spasswd",request.getParameter("user_password"));
}
else
{
   out.println("<p>로그인 실패</p>");
   out.println("<p><a href=\"slogin.html\">로그인하기</a></p>");
}
%>
</body>
</html>