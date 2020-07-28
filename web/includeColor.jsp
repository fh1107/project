<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8"%> 
<%@ include file="colorValue.jspf"%>
<!DOCTYPE HTML> <!-- hello.jsp -->
<html>
<head>
 <meta charset="utf-8">
 <meta name="viewport" content="width=device-width,initial-scale=1">
   <title>include directive 예제</title>
 </head>
 <body bgcolor="<%=bodyBG_color%>">
   안녕하세요,다른 화일에서 값을 가져오는 include 예제 파일 includeColor.jsp 입니다.<br/>
   <input id="name" type="text" placeholder="홍길동" required><br/>
   <input type="submit" value="보내기">
 </body>
</html>