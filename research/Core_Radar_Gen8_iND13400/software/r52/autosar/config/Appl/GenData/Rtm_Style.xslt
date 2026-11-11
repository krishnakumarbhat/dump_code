<?xml version="1.0" encoding="ISO-8859-1" standalone="yes"?>
<!-- edited with XMLSpy v2009 sp1 (http://www.altova.com) by Vector Employee (Vector Informatik GmbH) -->
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output omit-xml-declaration="yes"/>
	<xsl:output method="html" doctype-public="-//W3C//DTD XHTML 1.0 Transitional//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"/>
	<xsl:variable name="DoLinebreakTransformation" select="true()"/>
	<xsl:variable name="PositiveResultColor">#7FBE4E</xsl:variable>
	<xsl:variable name="NegativeResultColor">#C02222</xsl:variable>
	<xsl:template match="/">
		<html>
			<head>
				<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
					<title>RtmGen</title>
					<style type="text/css">
      /* http://meyerweb.com/eric/tools/css/reset/ 
         v2.0 | 20110126
         License: none (public domain)
      */

      html, body, div, span, applet, object, iframe,
      h1, h2, h3, h4, h5, h6, p, blockquote, pre,
      a, abbr, acronym, address, big, cite, code,
      del, dfn, em, img, ins, kbd, q, s, samp,
      small, strike, strong, sub, sup, tt, var,
      b, u, i, center,
      dl, dt, dd, ol, ul, li,
      fieldset, form, label, legend,
      table, caption, tbody, tfoot, thead, tr, th, td,
      article, aside, canvas, details, embed, 
      figure, figcaption, footer, header, hgroup, 
      menu, nav, output, ruby, section, summary,
      time, mark, audio, video {
        margin: 0;
        padding: 0;
        border: 0;
        font-size: 100%;
        font: inherit;
        vertical-align: baseline;
      }
      /* HTML5 display-role reset for older browsers */
      article, aside, details, figcaption, figure, 
      footer, header, hgroup, menu, nav, section {
        display: block;
      }
      body {
        line-height: 1;
        background:url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAFCAYAAACNbyblAAAAIUlEQVQImWNgYGBgWLp0qTEDFCCzyRBYunSpMaYKBgYGADlUDu9v7YIeAAAAAElFTkSuQmCC);
        font-family: Calibri, Verdana, Tahoma, Sans Serif;
        margin-top: 20px;
        margin-bottom: 20px;
      }
      ol, ul {
        list-style: none;
      }
      blockquote, q {
        quotes: none;
      }
      blockquote:before, blockquote:after,
      q:before, q:after {
        content: '';
        content: none;
      }
      table {
        border-collapse: collapse;
        border-spacing: 0;
        width: 100%;
      }
      
      table.setup {
        font-size:14px;
      }
      
      table td {
        padding: 4px;
        color: #666;
      }

      table td.left {
        color: #666;
        font-weight: bold;
      }

      table td.right {
        width: 700px;
      }
      
      table.testpattern td.title {
        font-weight: bold;
      }
      
      table.testpattern td.highlight {
        color: #666;
        font-weight: bold;
      }
      
      ::selection {
        color: #FFF;
        background: rgb(183,0,50);
      }
      
      ::-moz-selection {
        color: #FFF;
        background: rgb(183,0,50);
      }
      
      .container {
        width: 1000px;
        margin: auto;
      }
      
      .header {
        width:1020px;
        font-size: 32px;
        font-weight: bolder;
        text-align: center;
        color: #333;
        text-shadow: 0 1px 0 #FFF;
        opacity: 0.9;
        padding: 30px 0 30px;
        border: 1px solid #aaa;
        background: rgb(216,216,216);
        background: -webkit-linear-gradient(top, rgba(216,216,216,1) 0%,rgba(193,193,193,1) 100%);
        background: -moz-linear-gradient(top, rgba(216,216,216,1) 0%, rgba(193,193,193,1) 100%);
        background: -o-linear-gradient(top, rgba(216,216,216,1) 0%, rgba(193,193,193,1) 100%);
        background: -ms-linear-gradient(top, rgba(216,216,216,1) 0%, rgba(193,193,193,1) 100%);
        background: linear-gradient(top, rgba(216,216,216,1) 0%, rgba(193,193,193,1) 100%);
        -moz-box-shadow: 0 0 5px #bbb;
        -webkit-box-shadow: 0 0 5px #bbb;
        box-shadow: 0 0 5px #bbb;
        -webkit-transition: all 0.5s ease;
        -moz-transition: all 0.5s ease;
        -o-transition: all 0.5s ease;
      }
      
      .header:hover {
        cursor: default;
        color: rgb(183, 0, 50);
        text-shadow: 0 0px 8px #FFF;
        -webkit-box-shadow: 0px 0px 10px #999;
        -moz-box-shadow: 0px 0px 10px #999;
        box-shadow: 0px 0px 10px #999;
      }
      
      .overallpassed {
        text-align: center;
        font-size: 26px;
        font-weight: bolder;
        color: <xsl:copy-of select="$PositiveResultColor"/>;
      }
      
      .overallfailed {
        text-align: center;
        font-size: 26px;
        font-weight: bolder;
        color: <xsl:copy-of select="$NegativeResultColor"/>;
      }
      
      /* Inspired by http://hellohappy.org/css3-buttons/ */
      .box {
        width: 100%;
        margin-left: auto;
        margin-right: auto;
        margin-top: 20px;
        background: rgb(204, 204, 204);
        background: rgba(204, 204, 204, 0.5);
        text-shadow: 0 1px 0 #fff;
        border: 1px solid #bbb;
        -webkit-box-shadow: inset 0 0 1px 1px #f6f6f6;
        -moz-box-shadow: inset 0 0 1px 1px #f6f6f6;
        -ms-box-shadow: inset 0 0 1px 1px #f6f6f6;
        -o-box-shadow: inset 0 0 1px 1px #f6f6f6;
        box-shadow: inset 0 0 1px 1px #f6f6f6;
        color: #333;
        line-height: 1;
        padding: 8px 10px 9px;
        display: table;
      }
      
      /* Inspired by http://hellohappy.org/css3-buttons/ */
      .testpattern-box {
        margin-top: 10px;
        padding-left: 4px;
        background: rgb(240, 240, 240);
        background: rgba(255, 255, 255, 0.4);
        border: 1px solid #bbb;
        -webkit-box-shadow: inset 0 0 1px 1px #f6f6f6;
        -moz-box-shadow: inset 0 0 1px 1px #f6f6f6;
        -ms-box-shadow: inset 0 0 1px 1px #f6f6f6;
        -o-box-shadow: inset 0 0 1px 1px #f6f6f6;
        box-shadow: inset 0 0 1px 1px #f6f6f6;
        color: #333;
      }
      
      .box .top {
        font-size: 20px;
        font-weight: bolder;
        text-align: center;
      }
      
      .table-title {
        font-size: 16px;
        font-weight: bold;
        float: left;
        margin-bottom: 8px;
      }
      
      .testcase-verdict {
        float:right;
      }

      .badge {
        font-size: 14px;
        font-weight: bold;
        width: 90px;
        color: #fff;
        padding: 4px 0 5px 0;
        text-align: center;
        opacity: 0.9;
      }
      
      /* Inspired by http://hellohappy.org/css3-buttons/ */
      .badge#passed {
        text-shadow: 0 -1px 0 #449022;
        background: <xsl:copy-of select="$PositiveResultColor"/>;
        border: 1px solid #64A622;
        -webkit-box-shadow: inset 0 1px 0 0 #99CC66;
        -moz-box-shadow: inset 0 1px 0 0 #99CC66;
        -ms-box-shadow: inset 0 1px 0 0 #99CC66;
        -o-box-shadow: inset 0 1px 0 0 #99CC66;
        box-shadow: inset 0 1px 0 0 #99CC66;
      }
      
      /* Inspired by http://hellohappy.org/css3-buttons/ */
      .badge#failed {
        text-shadow: 0 -1px 0 #449022;
        background: <xsl:copy-of select="$NegativeResultColor"/>;
        border: 1px solid #A52B22;
        -webkit-box-shadow: inset 0 1px 0 0 #CC6666;
        -moz-box-shadow: inset 0 1px 0 0 #CC6666;
        -ms-box-shadow: inset 0 1px 0 0 #CC6666;
        -o-box-shadow: inset 0 1px 0 0 #CC6666;
        box-shadow: inset 0 1px 0 0 #CC6666;
      }
      
      #margins {
        margin-top: 10px;
        margin-bottom: 10px;
      }
      
      .separator {
        border: 0;
        height: 1px;
        background: #666;
        background: -webkit-linear-gradient(left, rgba(0, 0, 0, 0), rgba(0, 0, 0, .4), rgba(0, 0, 0, 0));
        background: -moz-linear-gradient(left, rgba(0, 0, 0, 0), rgba(0, 0, 0, .4), rgba(0, 0, 0, 0));
        background: -ms-linear-gradient(left, rgba(0, 0, 0, 0), rgba(0, 0, 0, .4), rgba(0, 0, 0, 0));
        background: -o-linear-gradient(left, rgba(0, 0, 0, 0), rgba(0, 0, 0, .4), rgba(0, 0, 0, 0)); 
        background: linear-gradient(left, rgba(0, 0, 0, 0), rgba(0, 0, 0, .4), rgba(0, 0, 0, 0)); 
      }
    </style>
				</meta>
			</head>
			<body>
				<div class="container">
					<div class="header">&gt;&gt; <xsl:value-of select="testmodule/title"/> &lt;&lt;</div>
					<xsl:variable name="overallverdict">
						<xsl:choose>
							<xsl:when test="testmodule/verdict/@result='pass'">overallpassed</xsl:when>
							<xsl:when test="testmodule/verdict/@result='fail'">overallfailed</xsl:when>
						</xsl:choose>
					</xsl:variable>
					<div class="box">
						<div class="{$overallverdict}">
							<xsl:choose>
								<xsl:when test="testmodule/verdict/@result='pass'">
									<xsl:text>All Tests Completed</xsl:text>
								</xsl:when>
								<xsl:when test="testmodule/verdict/@result='fail'">
									<xsl:text>Tests Incomplete</xsl:text>
								</xsl:when>
							</xsl:choose>
						</div>
					</div>
					<div class="box">
						<div class="top">General Test Information</div>
						<xsl:if test="testmodule/engineer">
							<div id="margins" class="separator"/>
							<div class="table-title">Test Engineer</div>
							<table class="setup">
								<xsl:for-each select="testmodule/engineer/xinfo">
									<tr>
										<td class="left">
											<xsl:value-of select="name"/>
										</td>
										<td class="right">
											<xsl:call-template name="replacelinebreak">
												<xsl:with-param name="srcnode">
													<xsl:value-of select="description"/>
												</xsl:with-param>
											</xsl:call-template>
										</td>
									</tr>
								</xsl:for-each>
								<xsl:for-each select="testmodule/engineer/info">
									<tr>
										<td class="left">
											<xsl:value-of select="name"/>
										</td>
										<td class="right">
											<xsl:call-template name="replacelinebreak">
												<xsl:with-param name="srcnode">
													<xsl:value-of select="description"/>
												</xsl:with-param>
											</xsl:call-template>
										</td>
									</tr>
								</xsl:for-each>
							</table>
						</xsl:if>
						<xsl:if test="testmodule/testsetup">
							<div id="margins" class="separator"/>
							<div class="table-title">Test Setup</div>
							<table class="setup">
								<xsl:for-each select="testmodule/testsetup/xinfo">
									<tr>
										<td class="left">
											<xsl:value-of select="name"/>
										</td>
										<td class="right">
											<xsl:call-template name="replacelinebreak">
												<xsl:with-param name="srcnode">
													<xsl:value-of select="description"/>
												</xsl:with-param>
											</xsl:call-template>
										</td>
									</tr>
								</xsl:for-each>
								<xsl:for-each select="testmodule/testsetup/info">
									<tr>
										<td class="left">
											<xsl:value-of select="name"/>
										</td>
										<td class="right">
											<xsl:call-template name="replacelinebreak">
												<xsl:with-param name="srcnode">
													<xsl:value-of select="description"/>
												</xsl:with-param>
											</xsl:call-template>
										</td>
									</tr>
								</xsl:for-each>
							</table>
						</xsl:if>
						<div id="margins" class="separator"/>
						<table class="setup">
							<xsl:call-template name="beginend">
								<xsl:with-param name="what">Test</xsl:with-param>
								<xsl:with-param name="begin">
									<xsl:value-of select="testmodule/@starttime"/>
								</xsl:with-param>
								<xsl:with-param name="beginTimestamp">
									<xsl:value-of select="testmodule/@timestamp"/>
								</xsl:with-param>
								<xsl:with-param name="end">
									<xsl:value-of select="testmodule/verdict/@endtime"/>
								</xsl:with-param>
								<xsl:with-param name="endTimestamp">
									<xsl:value-of select="testmodule/verdict/@endtimestamp"/>
								</xsl:with-param>
							</xsl:call-template>
						</table>
					</div>
					<xsl:apply-templates select="testmodule"/>
				</div>
			</body>
		</html>
	</xsl:template>
	<!-- Template: Test Module -->
	<xsl:template match="testmodule|testcycle">
		<xsl:apply-templates select="./testcase|./testgroup"/>
	</xsl:template>
	<!-- Template Test group -->
	<xsl:template match="testgroup">
		<xsl:variable name="hasTestSteps">
			<xsl:choose>
				<xsl:when test="count(descendant::teststep) > 0">true</xsl:when>
				<xsl:otherwise>false</xsl:otherwise>
			</xsl:choose>
		</xsl:variable>
		<xsl:if test="$hasTestSteps='true'">
			<xsl:variable name="hasSubGroups">
				<xsl:choose>
					<xsl:when test="count(child::testgroup) > 0">true</xsl:when>
					<xsl:otherwise>false</xsl:otherwise>
				</xsl:choose>
			</xsl:variable>
			<xsl:if test="$hasSubGroups='true'">
				<br/>
				<div id="margins" class="separator"/>
				<div class="box">
					<div class="top">
						<xsl:number level="multiple" count="testcase|testgroup"/>
						<xsl:text> </xsl:text>
						<xsl:if test="ident">
							<xsl:text> </xsl:text>
							<xsl:value-of select="ident"/>
						</xsl:if>
						<xsl:value-of select="title"/>
					</div>
				</div>
				<xsl:apply-templates select="child::testgroup|child::testcase"/>
			</xsl:if>
			<xsl:if test="$hasSubGroups='false'">
				<xsl:if test="count(ancestor::testgroup) = 0">
					<br/>
					<div id="margins" class="separator"/>
				</xsl:if>
				<div class="box">
					<div class="top">
						<xsl:if test="count(ancestor::testgroup) > 0">
							<xsl:number level="multiple" count="testcase|testgroup"/>
							<xsl:text> </xsl:text>
						</xsl:if>
						<xsl:if test="ident">
							<xsl:text> </xsl:text>
							<xsl:value-of select="ident"/>
						</xsl:if>
						<xsl:value-of select="title"/>
					</div>
					<xsl:apply-templates select="child::testcase"/>
				</div>
			</xsl:if>
		</xsl:if>
	</xsl:template>
	<!-- Template: Test Case -->
	<xsl:template match="testcase">
		<div id="margins" class="separator"/>
		<div class="table-title">
			<xsl:choose>
				<xsl:when test="ident">
					<xsl:value-of select="ident"/>
					<xsl:text>: </xsl:text>
					<xsl:value-of select="title"/>
				</xsl:when>
				<xsl:otherwise>
					<xsl:value-of select="title"/>
				</xsl:otherwise>
			</xsl:choose>
		</div>
		<xsl:variable name="badgeid">
			<xsl:choose>
				<xsl:when test="verdict/@result='pass'">passed</xsl:when>
				<xsl:when test="verdict/@result='fail'">failed</xsl:when>
				<xsl:when test="verdict/@result='na'">failed</xsl:when>
			</xsl:choose>
		</xsl:variable>
		<div class="testcase-verdict">
			<div class="badge" id="{$badgeid}">
				<xsl:choose>
					<xsl:when test="verdict/@result='pass'">complete</xsl:when>
					<xsl:when test="verdict/@result='fail'">incomplete</xsl:when>
					<xsl:when test="verdict/@result='na'">not executed</xsl:when>
				</xsl:choose>
			</div>
		</div>
		<table class="testcase">
			<xsl:call-template name="beginend">
				<xsl:with-param name="what">Test</xsl:with-param>
				<xsl:with-param name="begin">
					<xsl:value-of select="@starttime"/>
				</xsl:with-param>
				<xsl:with-param name="beginTimestamp">
					<xsl:value-of select="@timestamp"/>
				</xsl:with-param>
				<xsl:with-param name="end">
					<xsl:value-of select="verdict/@endtime"/>
				</xsl:with-param>
				<xsl:with-param name="endTimestamp">
					<xsl:value-of select="verdict/@endtimestamp"/>
				</xsl:with-param>
			</xsl:call-template>
		</table>
		<xsl:if test="testpattern">
				<div class="testpattern-box">
					<table class="testpattern">
						<tr>
							<td class="title" width="80">Timestamp</td>
							<td class="title" width="150">Test Step</td>
							<td class="title" width="200">Description</td>
						</tr>
						<tr>
							<td colspan="3">
								<div class="separator"/>
							</td>
						</tr>
						<xsl:apply-templates select="testpattern/teststep[contains(@type,'user')='true']">
							<xsl:sort select="@ident"/> 
						</xsl:apply-templates>
					</table>
				</div>
		</xsl:if>
	</xsl:template>
	<!-- Template: Test Pattern -->
	<xsl:template name="testpattern">
		<xsl:if test="not(result/@result='skip')">
			<xsl:if test="count(teststep) > 0">
				<xsl:apply-templates select="teststep"/>
			</xsl:if>
		</xsl:if>
	</xsl:template>
	<!-- Template: Test Step -->
	<xsl:template match="teststep">
		<xsl:variable name="tdclass">
			<xsl:choose>
				<xsl:when test="@type='user'">highlight</xsl:when>
				<xsl:otherwise/>
			</xsl:choose>
			<xsl:choose>
				<xsl:when test="@type='auto'"></xsl:when>
				<xsl:otherwise/>
			</xsl:choose>
		</xsl:variable>
		<xsl:variable name="desc">
			<xsl:call-template name="fixunit">
				<xsl:with-param name="text">
					<xsl:value-of select="."/>
				</xsl:with-param>
			</xsl:call-template>
		</xsl:variable>
		<tr>
			<td class="{$tdclass}">
				<xsl:value-of select="@timestamp"/>
			</td>
			<td class="{$tdclass}">
				<xsl:call-template name="replacelinebreak">
					<xsl:with-param name="srcnode">
						<xsl:value-of select="substring-after(@ident,'_Meas_')"/> 
					</xsl:with-param>
				</xsl:call-template>
			</td>
			<td class="{$tdclass}">
				<xsl:call-template name="replacelinebreak">
					<xsl:with-param name="srcnode">
						<xsl:value-of select="$desc"/>
					</xsl:with-param>
				</xsl:call-template>
			</td>
		</tr>
	</xsl:template>
	<xsl:template match="teststep[@ident='Resume reason' or @ident='']"/>
	<!-- Template: begin/end section -->
	<xsl:template name="beginend">
		<xsl:param name="what"/>
		<xsl:param name="begin"/>
		<xsl:param name="beginTimestamp"/>
		<xsl:param name="end"/>
		<xsl:param name="endTimestamp"/>
		<tr>
			<td class="left">
				<xsl:value-of select="$what"/> begin:</td>
			<td class="right">
				<xsl:value-of select="$begin"/> (logging timestamp <xsl:value-of select="$beginTimestamp"/>)</td>
		</tr>
		<tr>
			<td class="left">
				<xsl:value-of select="$what"/> end:</td>
			<td class="right">
				<xsl:value-of select="$end"/> (logging timestamp <xsl:value-of select="$endTimestamp"/>)</td>
		</tr>
	</xsl:template>
	<!-- Template to replace us to &mu;s in time measurements -->
	<xsl:template name="fixunit">
		<xsl:param name="text"/>
		<xsl:choose>
			<xsl:when test="contains($text, 'us')">
				<xsl:value-of select="substring-before($text, 'us')"/>
				<xsl:text>&#956;s</xsl:text>
				<xsl:call-template name="fixunit">
					<xsl:with-param name="text" select="substring-after($text, 'us')"/>
				</xsl:call-template>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$text"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	<!-- Templates for line break replacement \n => <br/> -->
	<xsl:template name="replacelinebreak">
		<xsl:param name="srcnode"/>
		<xsl:apply-templates select="$srcnode/child::* | $srcnode/text()" mode="replacelinebreak"/>
	</xsl:template>
	<xsl:template name="replacetextlinebreak">
		<xsl:param name="text"/>
		<xsl:choose>
			<xsl:when test="$DoLinebreakTransformation=true()">
				<xsl:choose>
					<xsl:when test="contains($text, '\n')">
						<xsl:variable name="head">
							<xsl:value-of select="substring-before($text, '\n')"/>
						</xsl:variable>
						<xsl:choose>
							<xsl:when test="substring($head, string-length($head), 1) = '\'">
								<!-- escaped: "\\n" => "\n" instead of line break -->
								<xsl:value-of select="$head"/>
								<xsl:text>n</xsl:text>
							</xsl:when>
							<xsl:otherwise>
								<xsl:value-of select="$head"/>
								<br/>
							</xsl:otherwise>
						</xsl:choose>
						<xsl:call-template name="replacetextlinebreak">
							<xsl:with-param name="text" select="substring-after($text, '\n')"/>
						</xsl:call-template>
					</xsl:when>
					<xsl:otherwise>
						<xsl:value-of select="$text"/>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$text"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	<xsl:template match="text()" mode="replacelinebreak" priority="2">
		<xsl:call-template name="replacetextlinebreak">
			<xsl:with-param name="text">
				<xsl:value-of select="."/>
			</xsl:with-param>
		</xsl:call-template>
	</xsl:template>
	<xsl:template match="node()" mode="replacelinebreak">
		<xsl:element name="{name()}">
			<xsl:for-each select="@*">
				<xsl:attribute name="{name()}"><xsl:value-of select="."/></xsl:attribute>
			</xsl:for-each>
			<xsl:apply-templates select="child::*|text()" mode="replacelinebreak"/>
		</xsl:element>
	</xsl:template>
</xsl:stylesheet>

