

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Oct 28 18:39:07 2010
 */
/* Compiler settings for dsspref.odl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __Dss_Info_h__
#define __Dss_Info_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDssPref_FWD_DEFINED__
#define __IDssPref_FWD_DEFINED__
typedef interface IDssPref IDssPref;
#endif 	/* __IDssPref_FWD_DEFINED__ */


#ifndef __DssPref_FWD_DEFINED__
#define __DssPref_FWD_DEFINED__

#ifdef __cplusplus
typedef class DssPref DssPref;
#else
typedef struct DssPref DssPref;
#endif /* __cplusplus */

#endif 	/* __DssPref_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __DSS_INFO_LIBRARY_DEFINED__
#define __DSS_INFO_LIBRARY_DEFINED__

/* library DSS_INFO */
/* [version][uuid] */ 


DEFINE_GUID(LIBID_DSS_INFO,0xC8870363,0x7B2A,0x11D2,0xB7,0xA1,0xA7,0xB0,0x0D,0x60,0x43,0x27);

#ifndef __IDssPref_DISPINTERFACE_DEFINED__
#define __IDssPref_DISPINTERFACE_DEFINED__

/* dispinterface IDssPref */
/* [uuid] */ 


DEFINE_GUID(DIID_IDssPref,0xC8870361,0x7B2A,0x11D2,0xB7,0xA1,0xA7,0xB0,0x0D,0x60,0x43,0x27);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("C8870361-7B2A-11D2-B7A1-A7B00D604327")
    IDssPref : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IDssPrefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDssPref * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDssPref * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDssPref * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDssPref * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDssPref * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDssPref * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDssPref * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IDssPrefVtbl;

    interface IDssPref
    {
        CONST_VTBL struct IDssPrefVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDssPref_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDssPref_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDssPref_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDssPref_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDssPref_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDssPref_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDssPref_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IDssPref_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_DssPref,0xC8870362,0x7B2A,0x11D2,0xB7,0xA1,0xA7,0xB0,0x0D,0x60,0x43,0x27);

#ifdef __cplusplus

class DECLSPEC_UUID("C8870362-7B2A-11D2-B7A1-A7B00D604327")
DssPref;
#endif
#endif /* __DSS_INFO_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


