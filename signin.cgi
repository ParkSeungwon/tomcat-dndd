#!/usr/bin/python
#-*- coding: utf-8 -*-
import cgi
from sqlalchemy import create_engine
from pandas import read_sql
import cgitb
cgitb.enable()
form = cgi.FieldStorage()
email = form.getvalue('id')
password = form.getvalue('password')
db = form.getvalue('group')

print "Content-type:text/html\r\n"
print '<h2>hello cgi here</h2>' 
conn = create_engine('mysql://dndd:dndddndd@localhost/'+db+'?charset=utf8')
df = read_sql("select * from Users where email = '" + email + "' order by date desc limit 1;", conn)
if df.size > 0: 
    print "email already exist"
else:
    conn.execute(u"insert into 회원 values ('" + email + "','" + unicode(name, 'utf8') + "','" + password + "','" + unicode(address,'utf8') + "','" + tel + "', 1);")
    print '가입완료'    
