import codecs;

fp = codecs.open("main.tex","r","gbk");
str = fp.read();
fp.close();
fp = codecs.open("report.tex","w","utf-8");
fp.write(str);
fp.close();
