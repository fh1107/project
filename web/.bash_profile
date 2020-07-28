# .bash_profile

# Get the aliases and functions
if [ -f ~/.bashrc ]; then
	. ~/.bashrc
fi

# User specific environment and startup programs

PATH=$PATH:$HOME/.local/bin:$HOME/bin

export PATH

export JAVA_HOME=/usr/java/jdk1.8.0_91
export CATALINA_HOME=/usr/local/tomcat
export PATH=$PATH:$JAVA_HOME/bin:$CATALINA_HOME/bin
export JAVA_OPTS="-Dfile.encoding=UTF-8"
export CLASSPATH=.:$JAVA_HOME/lib/tools.jar:/home/s20131515/public_html/WEB-INF/classes:/home/s20131515/public_html/WEB-INF/lib/cos.jar:$CATALINA_HOME/lib/jsp-api.jar:$CATALINA_HOME/lib/servlet-api.jar:$CATALINA_HOME/lib/mysql-connector-java-5.1.39-bin.jar
