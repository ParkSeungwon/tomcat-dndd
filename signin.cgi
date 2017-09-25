#!/usr/bin/python
#-*- coding: utf-8 -*-
import cgi
from sqlalchemy import create_engine
from pandas import read_sql
import cgitb
cgitb.enable()
form = cgi.FieldStorage()
name = form.getvalue('table')

print "Content-type:text/html\r\n"
print name
