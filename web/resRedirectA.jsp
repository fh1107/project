<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8"%> 
<% request.setCharacterEncoding("utf-8");%>
<% response.setHeader("Cache-Control","no-cache"); %>
<!DOCTYPE html> <!--userRedirectA.jsp-->
<html>
<head>
 <meta http-equiv="Content-Type"content="text/html; charset=utf-8"/>
 <meta name="viewport" content="width=device-width,initial-scale=1">
 <title>Response 인스턴스 실습2</title>
 </head>
 <body>
 현재 페이지는 res_redirectA.jsp 입니다.<br/>
 하지만,res_redirectB.jsp로 제어 이동(redirect)합니다.
 <%response.sendRedirect("resRedirectB.jsp");%>
 </body>
 </html>