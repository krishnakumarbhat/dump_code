<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="html" doctype-system="http://www.w3.org/TR/html4/loose.dtd" doctype-public="-//W3C//DTD HTML 4.01 Transitional//EN"/>

<xsl:template match="coverity">
<html>
<head>
<title><xsl:value-of select="title"/></title>
</head>
<body>
  <table cellPadding="8" summary="summary">
    <tr bgColor="#4682B4">
      <td>Checker</td>
      <td>Number</td>
    </tr>
  <xsl:apply-templates select="error"/>
  </table>
</body>
</html>
</xsl:template>


<xsl:template match="error">
<tr bgcolor="#F8F8F2">
  <xsl:apply-templates select="checker"/>
  <xsl:apply-templates select="num"/>
</tr>
</xsl:template>


<xsl:template match="checker">
  <td><xsl:value-of select="."/></td>
</xsl:template>


<xsl:template match="num">
  <td><xsl:value-of select="."/></td>
</xsl:template>

</xsl:stylesheet>
