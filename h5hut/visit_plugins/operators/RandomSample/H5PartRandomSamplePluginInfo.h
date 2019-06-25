// ************************************************************************* //
//  File: H5PartRandomSamplePluginInfo.h
// ************************************************************************* //

#ifndef H5PARTRANDOMSAMPLE_PLUGIN_INFO_H
#define H5PARTRANDOMSAMPLE_PLUGIN_INFO_H
#include <OperatorPluginInfo.h>
#include <operator_plugin_exports.h>

class H5PartRandomSampleAttributes;

// ****************************************************************************
//  Class: H5PartRandomSamplePluginInfo
//
//  Purpose:
//    Five classes that provide all the information about an H5PartRandomSample operator
//
//  Programmer: cristina -- generated by xml2info
//  Creation:   Thu Mar 16 10:26:55 PDT 2006
//
//  Modifications:
//
// ****************************************************************************

class H5PartRandomSampleGeneralPluginInfo : public virtual GeneralOperatorPluginInfo
{
public:
	virtual char *GetName() const;
	virtual char *GetVersion() const;
	virtual char *GetID() const;
	virtual bool  EnabledByDefault() const;
};

class H5PartRandomSampleCommonPluginInfo : public virtual CommonOperatorPluginInfo, public virtual H5PartRandomSampleGeneralPluginInfo
{
public:
	virtual AttributeSubject *AllocAttributes();
	virtual void CopyAttributes(AttributeSubject *to, AttributeSubject *from);
};

class H5PartRandomSampleGUIPluginInfo : public virtual GUIOperatorPluginInfo, public virtual H5PartRandomSampleCommonPluginInfo
{
public:
	virtual const char *GetMenuName() const;
	virtual QvisPostableWindowObserver *CreatePluginWindow(int type,
	                                                       AttributeSubject *attr, QvisNotepadArea *notepad);
	virtual const char **XPMIconData() const;
};

class H5PartRandomSampleViewerPluginInfo : public virtual ViewerOperatorPluginInfo, public virtual H5PartRandomSampleCommonPluginInfo
{
public:
	virtual AttributeSubject *GetClientAtts();
	virtual AttributeSubject *GetDefaultAtts();
	virtual void SetClientAtts(AttributeSubject *atts);
	virtual void GetClientAtts(AttributeSubject *atts);

	virtual void InitializeOperatorAtts(AttributeSubject *atts,
	                                    const ViewerPlot *plot,
	                                    const bool fromDefault);
	virtual const char **XPMIconData() const;

	static void InitializeGlobalObjects();
private:
	static H5PartRandomSampleAttributes *defaultAtts;
	static H5PartRandomSampleAttributes *clientAtts;
};

class H5PartRandomSampleEnginePluginInfo : public virtual EngineOperatorPluginInfo, public virtual H5PartRandomSampleCommonPluginInfo
{
public:
	virtual avtPluginFilter *AllocAvtPluginFilter();
};

class H5PartRandomSampleScriptingPluginInfo : public virtual ScriptingOperatorPluginInfo, public virtual H5PartRandomSampleCommonPluginInfo
{
public:
	virtual void InitializePlugin(AttributeSubject *subj, void *data);
	virtual void *GetMethodTable(int *nMethods);
	virtual bool TypesMatch(void *pyobject);
	virtual char *GetLogString();
	virtual void SetDefaults(const AttributeSubject *atts);
};

#endif
