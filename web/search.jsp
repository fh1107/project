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
        <title> 로그인 실습</title> 
    </head>
<body>
<%
if (!isSessionOn((String)session.getAttribute("sid")) ||
  !isSessionOn((String)session.getAttribute("spasswd")))
{
  out.println("<header><h2>실습을 환영합니다.</h2><header>");
 out.println("<nav><ul>");
out.println("<li><a href=\"http://jsp.dju.ac.kr/~s20131515/login.html\">로그인</a></li>");
                out.println("<li><a href=\"http://jsp.dju.ac.kr/~s20131515/member.jsp\">회원가입</a></li>");
out.println("</ul></nav>");
out.println("<section>");
out.println("<p>로그인되지 않았습니다.</p>");
out.println("<p><a href=\"login.html\">로그인하기</a></p>");
out.println("</section>");
}
else{
out.println("<header><h2>실습을 환영합니다</h2></header>");
out.println("<nav><ul>");
out.println("<li><a href=\"http://jsp.dju.ac.kr/~s20131515/search.jsp\">회원검색</a></li>");
out.println("<li><a href=\"http://jsp.dju.ac.kr/~s20131515/logout.jsp\">로그아웃</a></li>");
out.println("</ul></nav>");
out.println("<section>");
out.println("<form action=\"search.jsp\"method=\"post\">");
out.println("<fieldset>");
out.println("<legend>검색</legend>");
out.println("<select name=\"search_select\">");
out.println("<option value=\"s_whole\"selected>전체</option>");
out.println("<option value=\"s_userid\">성별</option>");
out.println("<option value=\"s_name\">이름</option>");
out.println("<option value=\"s_email\">취미</option>");
out.println("</select>");
out.println("<input id=\"id_form\"type=\"text\" name=\"stud_search\"size=\"20\" maxlength=\"50\"/>");
out.println("<input type=\"submin\" value=\"검색\">");
out.println("</fieldset>");
out.println("</form>");
out.println("</section>");
 out.println("<footer><p>&copy;20XX Made by Korea. All rights reserved.</p> </footer>"); 
}
%>
</body></html>