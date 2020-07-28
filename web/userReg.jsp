<%@ page language="java" contentType="text/html; charset=utf-8" pageEncoding="utf-8"%> 
<% request.setCharacterEncoding("utf-8");%>
<%@ page import="java.util.ArrayList"%>
<!DOCTYPE html> <!--userLogin.jsp-->
<html>
<head>
 <meta http-equiv="Content-Type"content="text/html; charset=utf-8"/>
 <meta name="viewport" content="width=device-width,initial-scale=1">
  <!--[if it IE 9]>
 <script src="http://html5shiv.googlecode.com/svn/trunk/html5.js">
 </script>
 <![endif]-->
 <style>
 body {font-family: Verdana, sans-serif;font-size:0.8em;}
 header,nav,section,article,footer
 {border:1px solid gray; margin:5px; padding:8px;}
 nav ul {margin:0;padding:0;}
 nav ul li {display:inline;margin:5px;}
 .id_form {width:100px;height:14px;color:red;}
 </style>
 <title>로그인 실습</title>
 </head>
 <body>
 <header>
 <h2>실습을 환영합니다<h2></header>
 <nav>
 <ul>
  <li><a href="www.dju.ac.kr">로그인</a></li>
  <li><a href="hive.dju.ac.kr">조회</a></li>
  </ul></nav>
  <section>
  <fieldset><legend>회원정보</legend>
  <fieldset><legend>이름/이메일</legend>
  <label for="stud_name">이름</label>
  <label class="id_form"><%=request.getParameter("stud_name")%></label><br/>
  <label for="stud_email">이메일</label>
  <label class="id_form"><%=request.getParameter("stud_email")%></label><br/>
  <label for="stud_phone">전화번호</label>
  <label class="id_form"><%=request.getParameter("stud_phone")%></label><br/>
  </fieldset>
  <fieldset><legend>성별</legend>
   <label class="id_form"><%=request.getParameter("stud_gender")%></label><br/>
  </fieldset>
  <fieldset><legend>취미</legend>
  <%
  ArrayList<String> myArrayList = new ArrayList<String>();
  for(int i=0;i<3;i++){
  String tmpType = request.getParameter("stud_hobby"+(i+1));
  //out.println(tmpType);
  if(tmpType!=null&&!"".equals(tmpType))
   myArrayList.add(tmpType);
  }
  for(int i=0;i< myArrayList.size();i++){
  out.println("취미 "+ (i+1) +"="+myArrayList.get(i) +"<br/>");
  }
  %>
  </fieldset>
  </fieldset>
  </form>
  </section>
  <footer>
  <p>&copy;20XX Made by Korea. All rights reserved.</p></footer>
  </body></html>
   