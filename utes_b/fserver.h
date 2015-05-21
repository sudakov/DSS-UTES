/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.15 */
/* at Sun Dec 10 19:14:55 2000
 */
/* Compiler settings for fserver.idl:
    Os, W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"

#ifndef __fserver_h__
#define __fserver_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 


#ifndef __FServer_LIBRARY_DEFINED__
#define __FServer_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: FServer
 * at Sun Dec 10 19:14:55 2000
 * using MIDL 3.00.15
 ****************************************/
/* [helpstring][version][uuid] */ 


typedef /* [version][uuid] */ struct  tagTICouple
    {
    BSTR Name1;
    BSTR Name2;
    double Mark;
    }	TICouple;

typedef /* [version][uuid] */ struct  tagTICLient
    {
    BSTR CritName;
    float RightRange;
    float Sensitivity;
    short FModeASK;
    }	TICLient;


EXTERN_C const IID LIBID_FServer;

#ifndef __IRibbaFServer_INTERFACE_DEFINED__
#define __IRibbaFServer_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IRibbaFServer
 * at Sun Dec 10 19:14:55 2000
 * using MIDL 3.00.15
 ****************************************/
/* [auto_handle][oleautomation][helpstring][version][uuid] */ 



EXTERN_C const IID IID_IRibbaFServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IRibbaFServer : public IUnknown
    {
    public:
        virtual /* [id] */ HRESULT __stdcall RegistUser( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [id] */ HRESULT __stdcall UnregistUser( void) = 0;
        
        virtual /* [id] */ HRESULT __stdcall SetCouple( 
            /* [in] */ BSTR Name1,
            /* [in] */ BSTR Name2,
            /* [in] */ double Mark) = 0;
        
        virtual /* [id][propget] */ HRESULT __stdcall get_GetCouple( 
            /* [in] */ BSTR Name1,
            /* [in] */ BSTR Name2,
            /* [retval][out] */ TICouple __RPC_FAR *Value) = 0;
        
        virtual /* [id][propget] */ HRESULT __stdcall get_RegistClient( 
            /* [in] */ BSTR CritName,
            /* [retval][out] */ TICLient __RPC_FAR *Value) = 0;
        
        virtual /* [id] */ HRESULT __stdcall SaveClient( 
            /* [in] */ TICLient Value) = 0;
        
        virtual /* [id] */ HRESULT __stdcall CodeString( 
            /* [in] */ BSTR InStr,
            /* [retval][out] */ BSTR __RPC_FAR *OutStr) = 0;
        
        virtual /* [id] */ HRESULT __stdcall OutMessage( 
            /* [in] */ BSTR MSG) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRibbaFServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRibbaFServer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRibbaFServer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRibbaFServer __RPC_FAR * This);
        
        /* [id] */ HRESULT ( __stdcall __RPC_FAR *RegistUser )( 
            IRibbaFServer __RPC_FAR * This,
            /* [in] */ BSTR FileName);
        
        /* [id] */ HRESULT ( __stdcall __RPC_FAR *UnregistUser )( 
            IRibbaFServer __RPC_FAR * This);
        
        /* [id] */ HRESULT ( __stdcall __RPC_FAR *SetCouple )( 
            IRibbaFServer __RPC_FAR * This,
            /* [in] */ BSTR Name1,
            /* [in] */ BSTR Name2,
            /* [in] */ double Mark);
        
        /* [id][propget] */ HRESULT ( __stdcall __RPC_FAR *get_GetCouple )( 
            IRibbaFServer __RPC_FAR * This,
            /* [in] */ BSTR Name1,
            /* [in] */ BSTR Name2,
            /* [retval][out] */ TICouple __RPC_FAR *Value);
        
        /* [id][propget] */ HRESULT ( __stdcall __RPC_FAR *get_RegistClient )( 
            IRibbaFServer __RPC_FAR * This,
            /* [in] */ BSTR CritName,
            /* [retval][out] */ TICLient __RPC_FAR *Value);
        
        /* [id] */ HRESULT ( __stdcall __RPC_FAR *SaveClient )( 
            IRibbaFServer __RPC_FAR * This,
            /* [in] */ TICLient Value);
        
        /* [id] */ HRESULT ( __stdcall __RPC_FAR *CodeString )( 
            IRibbaFServer __RPC_FAR * This,
            /* [in] */ BSTR InStr,
            /* [retval][out] */ BSTR __RPC_FAR *OutStr);
        
        /* [id] */ HRESULT ( __stdcall __RPC_FAR *OutMessage )( 
            IRibbaFServer __RPC_FAR * This,
            /* [in] */ BSTR MSG);
        
        END_INTERFACE
    } IRibbaFServerVtbl;

    interface IRibbaFServer
    {
        CONST_VTBL struct IRibbaFServerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRibbaFServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRibbaFServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRibbaFServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRibbaFServer_RegistUser(This,FileName)	\
    (This)->lpVtbl -> RegistUser(This,FileName)

#define IRibbaFServer_UnregistUser(This)	\
    (This)->lpVtbl -> UnregistUser(This)

#define IRibbaFServer_SetCouple(This,Name1,Name2,Mark)	\
    (This)->lpVtbl -> SetCouple(This,Name1,Name2,Mark)

#define IRibbaFServer_get_GetCouple(This,Name1,Name2,Value)	\
    (This)->lpVtbl -> get_GetCouple(This,Name1,Name2,Value)

#define IRibbaFServer_get_RegistClient(This,CritName,Value)	\
    (This)->lpVtbl -> get_RegistClient(This,CritName,Value)

#define IRibbaFServer_SaveClient(This,Value)	\
    (This)->lpVtbl -> SaveClient(This,Value)

#define IRibbaFServer_CodeString(This,InStr,OutStr)	\
    (This)->lpVtbl -> CodeString(This,InStr,OutStr)

#define IRibbaFServer_OutMessage(This,MSG)	\
    (This)->lpVtbl -> OutMessage(This,MSG)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT __stdcall IRibbaFServer_RegistUser_Proxy( 
    IRibbaFServer __RPC_FAR * This,
    /* [in] */ BSTR FileName);


void __RPC_STUB IRibbaFServer_RegistUser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT __stdcall IRibbaFServer_UnregistUser_Proxy( 
    IRibbaFServer __RPC_FAR * This);


void __RPC_STUB IRibbaFServer_UnregistUser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT __stdcall IRibbaFServer_SetCouple_Proxy( 
    IRibbaFServer __RPC_FAR * This,
    /* [in] */ BSTR Name1,
    /* [in] */ BSTR Name2,
    /* [in] */ double Mark);


void __RPC_STUB IRibbaFServer_SetCouple_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT __stdcall IRibbaFServer_get_GetCouple_Proxy( 
    IRibbaFServer __RPC_FAR * This,
    /* [in] */ BSTR Name1,
    /* [in] */ BSTR Name2,
    /* [retval][out] */ TICouple __RPC_FAR *Value);


void __RPC_STUB IRibbaFServer_get_GetCouple_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT __stdcall IRibbaFServer_get_RegistClient_Proxy( 
    IRibbaFServer __RPC_FAR * This,
    /* [in] */ BSTR CritName,
    /* [retval][out] */ TICLient __RPC_FAR *Value);


void __RPC_STUB IRibbaFServer_get_RegistClient_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT __stdcall IRibbaFServer_SaveClient_Proxy( 
    IRibbaFServer __RPC_FAR * This,
    /* [in] */ TICLient Value);


void __RPC_STUB IRibbaFServer_SaveClient_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT __stdcall IRibbaFServer_CodeString_Proxy( 
    IRibbaFServer __RPC_FAR * This,
    /* [in] */ BSTR InStr,
    /* [retval][out] */ BSTR __RPC_FAR *OutStr);


void __RPC_STUB IRibbaFServer_CodeString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT __stdcall IRibbaFServer_OutMessage_Proxy( 
    IRibbaFServer __RPC_FAR * This,
    /* [in] */ BSTR MSG);


void __RPC_STUB IRibbaFServer_OutMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRibbaFServer_INTERFACE_DEFINED__ */


#ifdef __cplusplus
EXTERN_C const CLSID CLSID_RibbaFServer;

class RibbaFServer;
#endif
#endif /* __FServer_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
