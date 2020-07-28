<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<%!
boolean isSessionOn(String str) 
{
if((str==null) || str.equals("")) return false;
return true;
}
%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
      <meta name="viewport" content="width=device-width, initial-scale=1"/>
   <style> 
        body {font-family: Verdana,sans-serif; font-size:0.8em;} 
        header, nav, section, article, footer 
        {border: 1px solid gray; margin:5px; padding:8px;} 
        nav ul {margin:0; padding:0;} 
        nav ul li {display:inline; margin:5px;}
        .id_form {width:100px; height: 14px; color:red;} 
        </style> 
        <title>회원가입</title> 
    </head>
<body>
<% session.invalidate();
   out.println("<header><h2>실습을 환영합니다.</h2><header>");
   out.println("<nav><ul>");
   out.println("<li><a href=\"http://jsp.dju.ac.kr/~s20131515/login.html\">로그인</a></li>");
   out.println("<li><a href=\"http://jsp.dju.ac.kr/~s20131515/search.jsp\">회원검색</a></li>");
   out.println("<li><a href=\"http://jsp.dju.ac.kr/~s20141515/member.jsp\">회원가입</a></li>");
   out.println("<li><a href=\"http://jsp.dju.ac.kr/~s20131515/logout.jsp\">로그아웃</a></li>");
   out.println("</ul></nav>");
   out.println("<section>");
   out.println("<p>로그아웃 하셨습니다.");
   out.println("<p><a href=\"http://jsp.dju.ac.kr/~s20131515/index.html\">홈페이지</a></p>");
   out.println("<footer><p>&copy;20XX Made by Korea. All rights reserved.</p> </footer>"); 
%>
</body>
