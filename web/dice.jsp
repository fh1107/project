<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<!DOCTYPE html> <!--dice.jsp-->
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<meta name="viewport" content="width=device-width, initial-scale=1"/>
</head>
<jsp:useBean id="dice" class="bean.user.Dice" scope="request" />
<body>
<h2> 주사위 2번 던지기 </h2>
주사위1 : <jsp:getProperty name="dice" property="num" /> <br/>
주사위2 : <jsp:getProperty name="dice" property="num" /> <br/>
<br>
<a href="dice.jsp"> 주사위 다시 던지기</a>
</body>
</html>