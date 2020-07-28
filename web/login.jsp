<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<%! boolean isSessionOn(String str) { if( (str == null) || str.equals("")) return false;
    return true; }
%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<meta name="viewport" content="width=device-width, initial-scale=1"/>
<link rel="stylesheet" type="text/css" href="style.css"/>
<title>회원가입</title></head>
<body>
<%
if(!isSessionOn(request.getParameter("user_id")) || !isSessionOn(request.getParameter("user_password")))
{
    out.println("<header><h2>실습을 환영합니다</h2></header>");
    out.println("<nav><ul>");
    out.println("<li><a href=\"http://jsp.dju.ac.kr/~s20131515/login.html\">로그인</a></li>");
    out.println("<li><a href=\"http://jsp.dju.ac.kr/~s20131515/member.jsp\">회원가입</a></li>");
    out.println("</ul></nav>");
    out.println("<section>");
    out.println("<p> 정확히 입력하세요.</p>");
    out.println("<p> <a href=\"login.html\">로그인하기</a></p>");
    out.println("</section>");
    out.println("<footer><p>%copy;2016 Made by Koear. All rights reserved.</p> </footer>");
 return;
}
String userID = "admin";
String userPassword ="admin";
//아이디 오류
if(request.getParameter("user_id").equals(userID)&& request.getParameter("user_password").equals(userPassword))
{
session.setAttribute("sid",request.getParameter("user_id"));
session.setAttribute("spasswd",request.getParameter("user_password"));
out.println("<header><h2>실습을 환영합니다</h2></header>");
out.println("<nav><ul>");
out.println("<li><a href=\"http://jsp.dju.ac.kr/~s20131515/search.jsp\">회원검색</a></li>");
out.println("<li><a href=\"http://jsp.dju.ac.kr/~s20131515/logout.jsp\">로그아웃</a></li>");
out.println("</ul></nav>");
out.println("<section>");
out.println("<p> 로그인 하였습니다."+ (String)session.getAttribute("sid")+"님 - <a href=\"logout.jsp\">로그아웃</a></p>");
}else{
            out.println("<header><h2>실습을 환영합니다.</h2><header>");
            out.println("<nav><ul>");
            out.println("<li><a href=\"http://jsp.dju.ac.kr/~s20131515/login.html\">로그인</a></li>");
            out.println("<li><a href=\"http://jsp.dju.ac.kr/~s20131515/search.jsp\">회원검색</a></li>");      
            out.println("</ul></nav>");
            out.println("<section>");
            out.println("<p>정확히 입력하세요</p>");
            out.println("<p><a href=\"http://jsp.dju.ac.kr/~s20131515/login.html\">로그인하기.</a></p>");
            out.println("<section>");
            out.println("<footer><p>&copy;20XX Made by Korea. All rights reserved.</p> </footer>"); 
         }
%>
