<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<!DOCTYPE html> <!-- blogin.jsp -->
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<meta name="viewport" content="width=device-width, initial-scale=1"/>
<jsp:useBean id="mlogin" class="bean.user.Login">
 <jsp:setProperty name="mlogin" property="userName"/>
 <jsp:setProperty name="mlogin" property="userPasswd"/>
</jsp:useBean>
<title> Java bean 로그인 실습</title>
</head>
<body>
<jsp:getProperty name="mlogin" property="userName"/>님 반갑습니다.<br/>
<jsp:getProperty name="mlogin" property="userPasswd"/> 입니다.
</body>
</html>