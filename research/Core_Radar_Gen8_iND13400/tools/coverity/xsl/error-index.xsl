<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="html" doctype-system="http://www.w3.org/TR/html4/loose.dtd" doctype-public="-//W3C//DTD HTML 4.01 Transitional//EN"/>

<xsl:template match="coverity">
<html>
<head>
<title>
<xsl:value-of select="title"/>
</title>
</head>
<body bgcolor="#FFFFFF" text="#000000" link="#37598D" vlink="#5685AB">
  <center><h2><xsl:value-of select="title"/></h2></center>
  <xsl:if test="formaterrors">
  <table summary="navigation links"><tr>
  <xsl:apply-templates select="formaterrors"/>
  </tr></table>
  </xsl:if>
  <table cellPadding="8" summary="defects">
    <tr bgColor="#4682B4">
      <td>ID</td>
      <td>Checker</td>
      <td>File</td>
      <td>Line</td>
      <td>Function</td>
      <td>Classification</td>
    </tr>
  <xsl:apply-templates select="error"/>
  </table>
  <xsl:if test="formaterrors">
  <table summary="navigation links"><tr>
  <xsl:apply-templates select="formaterrors"/>
  </tr></table>
  </xsl:if>
</body>
</html>
</xsl:template>


<xsl:template match="formaterrors">
  <xsl:apply-templates select="link"/>
</xsl:template>

<xsl:template match="link">
  <td>
    <a><xsl:attribute name="href"><xsl:value-of select="."/></xsl:attribute>
    <xsl:value-of select="../value"/>
    </a>
  </td>
</xsl:template>

<xsl:template match="error">
<tr bgcolor="#F8F8F2" class="bodytextlarge">
  <xsl:apply-templates select="num"/>
  <xsl:apply-templates select="checker"/>
  <xsl:apply-templates select="file"/>
  <xsl:apply-templates select="line"/>

  <xsl:choose>
  <xsl:when test="unmangled_function">
  <xsl:apply-templates select="unmangled_function"/>
  </xsl:when>
  <xsl:otherwise>
  <xsl:apply-templates select="function"/>
  </xsl:otherwise>
  </xsl:choose>
  <xsl:apply-templates select="status"/>
</tr>
</xsl:template>


<xsl:template match="checker">
  <td><xsl:value-of select="."/></td>
</xsl:template>


<xsl:template match="file">
  <td>
  <xsl:choose>
    <xsl:when test="../home">
      <a><xsl:attribute name="href"><xsl:value-of select="../home"/>.html#error</xsl:attribute>
        <xsl:value-of select="."/>
      </a>
    </xsl:when>
    <xsl:otherwise>
        <xsl:value-of select="."/>
    </xsl:otherwise>
  </xsl:choose>
  </td>
</xsl:template>

<xsl:template match="line">
  <td><xsl:value-of select="."/></td>
</xsl:template>

<xsl:template match="unmangled_function">
  <td><xsl:value-of select="."/></td>
</xsl:template>

<xsl:template match="function">
  <td><xsl:value-of select="."/></td>
</xsl:template>

<xsl:template match="num">
  <td><xsl:value-of select="."/></td>
</xsl:template>

<xsl:template match="status">
  <td><xsl:value-of select="."/></td>
</xsl:template>


</xsl:stylesheet>
