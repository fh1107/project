<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<!DOCTYPE html> <!--dice3.jsp-->
<html>
<head>
<meta charset="utf-8"/>
<meta name="viewport" content="width=device-width, initial-scale=1"/>
<jsp:useBean id="dice3" class="bean.user.Dice3">
 <jsp:setProperty name="dice3" property="starNum"/>
 <jsp:setProperty name="dice3" property="endNum"/>
</jsp:useBean>
<title>Java bean 로그인 실습</title>
</head>
<body>
<h2> 입력된 숫자 사이의 난수 </h2>
난수 1 : <jsp:getProperty name="dice3" property="num1"/>
난수 2 : <jsp:getProperty name="dice3" property="num2"/> <br/>
최대값 : <jsp:getProperty name="dice3" property="maxNum"/>
최소값 : <jsp:getProperty name="dice3" property="minNum"/><br/>
<a href="dice3.html">다시 숫자 입력하기</a>
</body>
</html>