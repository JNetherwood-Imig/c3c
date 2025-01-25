// Copyright (c) 2019-2023 Christoffer Lerno. All rights reserved.
// Use of this source code is governed by the GNU LGPLv3.0 license
// a copy of which can be found in the LICENSE file.

// Only include this from compiler_common.h


#if IS_CLANG
#define FLAG_ATTR __attribute__((flag_enum))
#else
#define FLAG_ATTR
#endif

typedef enum
{
	ABI_UNKNOWN,
	ABI_X64,
	ABI_WIN64,
	ABI_X86,
	ABI_AARCH64,
	ABI_WASM,
	ABI_ARM,
	ABI_PPC32,
	ABI_PPC64_SVR4,
	ABI_RISCV,
	ABI_XTENSA,
} ABI;

typedef enum
{
	ABI_ARG_IGNORE,
	ABI_ARG_DIRECT,
	ABI_ARG_DIRECT_PAIR,
	ABI_ARG_DIRECT_COERCE,
	ABI_ARG_DIRECT_COERCE_INT,
	ABI_ARG_DIRECT_SPLIT_STRUCT_I32,
	ABI_ARG_EXPAND_COERCE,
	ABI_ARG_INDIRECT,
	ABI_ARG_EXPAND,
}  ABIKind;

typedef enum
{
	ANALYSIS_NOT_BEGUN,
	ANALYSIS_MODULE_HIERARCHY,
	ANALYSIS_MODULE_TOP,
	ANALYSIS_IMPORTS,
	ANALYSIS_REGISTER_GLOBAL_DECLARATIONS,
	ANALYSIS_INCLUDES,
	ANALYSIS_REGISTER_CONDITIONAL_UNITS,
	ANALYSIS_REGISTER_CONDITIONAL_DECLARATIONS,
	ANALYSIS_METHODS_REGISTER,
	ANALYSIS_METHODS_REGISTER_GENERIC,
	ANALYSIS_METHODS_INCLUDES,
	ANALYSIS_METHODS_INCLUDES_GENERIC,
	ANALYSIS_METHODS_CONDITIONAL,
	ANALYSIS_METHODS_CONDITIONAL_GENERIC,
	ANALYSIS_POST_REGISTER,
	ANALYSIS_DECLS,
	ANALYSIS_CT_ECHO,
	ANALYSIS_CT_ASSERT,
	ANALYSIS_FUNCTIONS,
	ANALYSIS_INTERFACE,
	ANALYSIS_FINALIZE,
	ANALYSIS_LAST = ANALYSIS_FINALIZE
} AnalysisStage;

// Note: This list is derived from Clang, only a subset is used by C3.
typedef enum
{
	ARCH_TYPE_UNKNOWN,
	ARCH_TYPE_ARM,          // ARM (little endian): arm, armv.*, xscale
	ARCH_TYPE_ARMB,         // ARM (big endian): armeb
	ARCH_TYPE_AARCH64,      // AArch64 (little endian): aarch64
	ARCH_TYPE_AARCH64_BE,   // AArch64 (big endian): aarch64_be
	ARCH_TYPE_AARCH64_32,   // AArch64 (little endian) ILP32: aarch64_32
	ARCH_TYPE_ARC,          // ARC: Synopsys ARC
	ARCH_TYPE_AVR,          // AVR: Atmel AVR microcontroller
	ARCH_TYPE_BPFEL,        // eBPF or extended BPF or 64-bit BPF (little endian)
	ARCH_TYPE_BPFEB,        // eBPF or extended BPF or 64-bit BPF (big endian)
	ARCH_TYPE_HEXAGON,      // Hexagon: hexagon
	ARCH_TYPE_MIPS,         // MIPS: mips, mipsallegrex, mipsr6
	ARCH_TYPE_MIPSEL,       // MIPSEL: mipsel, mipsallegrexe, mipsr6el
	ARCH_TYPE_MIPS64,       // MIPS64: mips64, mips64r6, mipsn32, mipsn32r6
	ARCH_TYPE_MIPS64EL,     // MIPS64EL: mips64el, mips64r6el, mipsn32el, mipsn32r6el
	ARCH_TYPE_MSP430,       // MSP430: msp430
	ARCH_TYPE_PPC,          // PPC: powerpc
	ARCH_TYPE_PPC64,        // PPC64: powerpc64, ppu
	ARCH_TYPE_PPC64LE,      // PPC64LE: powerpc64le
	ARCH_TYPE_R600,         // R600: AMD GPUs HD2XXX - HD6XXX
	ARCH_TYPE_AMDGCN,       // AMDGCN: AMD GCN GPUs
	ARCH_TYPE_RISCV32,      // RISC-V (32-bit): riscv32
	ARCH_TYPE_RISCV64,      // RISC-V (64-bit): riscv64
	ARCH_TYPE_SPARC,        // Sparc: sparc
	ARCH_TYPE_SPARCV9,      // Sparcv9: Sparcv9
	ARCH_TYPE_SPARCEL,      // Sparc: (endianness = little). NB: 'Sparcle' is a CPU variant
	ARCH_TYPE_SYSTEMZ,      // SystemZ: s390x
	ARCH_TYPE_TCE,          // TCE (http://tce.cs.tut.fi/): tce
	ARCH_TYPE_TCELE,        // TCE little endian (http://tce.cs.tut.fi/): tcele
	ARCH_TYPE_THUMB,        // Thumb (little endian): thumb, thumbv.*
	ARCH_TYPE_THUMBEB,      // Thumb (big endian): thumbeb
	ARCH_TYPE_X86,          // X86: i[3-9]86
	ARCH_TYPE_X86_64,       // X86-64: amd64, x86_64
	ARCH_TYPE_XCORE,        // XCore: xcore
	ARCH_TYPE_NVPTX,        // NVPTX: 32-bit
	ARCH_TYPE_NVPTX64,      // NVPTX: 64-bit
	ARCH_TYPE_LE32,         // le32: generic little-endian 32-bit CPU (PNaCl)
	ARCH_TYPE_LE64,         // le64: generic little-endian 64-bit CPU (PNaCl)
	ARCH_TYPE_AMDIL,        // AMDIL
	ARCH_TYPE_AMDIL64,      // AMDIL with 64-bit pointers
	ARCH_TYPE_HSAIL,        // AMD HSAIL
	ARCH_TYPE_HSAIL64,      // AMD HSAIL with 64-bit pointers
	ARCH_TYPE_SPIR,         // SPIR: standard portable IR for OpenCL 32-bit version
	ARCH_TYPE_SPIR64,       // SPIR: standard portable IR for OpenCL 64-bit version
	ARCH_TYPE_KALIMBA,      // Kalimba: generic kalimba
	ARCH_TYPE_SHAVE,        // SHAVE: Movidius vector VLIW processors
	ARCH_TYPE_LANAI,        // Lanai: Lanai 32-bit
	ARCH_TYPE_WASM32,       // WebAssembly with 32-bit pointers
	ARCH_TYPE_WASM64,       // WebAssembly with 64-bit pointers
	ARCH_TYPE_RSCRIPT32,    // 32-bit RenderScript
	ARCH_TYPE_RSCRIPT64,    // 64-bit RenderScript
	ARCH_TYPE_XTENSA,       // Xtensa
	ARCH_TYPE_LAST = ARCH_TYPE_XTENSA
} ArchType;

typedef enum
{
	ARM_AAPCS,
	ARM_AAPCS16,
	ARM_APCS_GNU,
	ARM_AAPCS_LINUX,
} ARMVariant;

typedef enum
{
	ARM_ABI_AAPCS,
	ARM_ABI_APCS,
	ARM_ABI_AAPCS16_VFP,
	ARM_ABI_AAPCS_VFP,
} ARMABIVariant;

typedef enum FLAG_ATTR
{
	ARG_BITS_8 = 1 << 0,
	ARG_BITS_16 = 1 << 1,
	ARG_BITS_32 = 1 << 2,
	ARG_BITS_64 = 1 << 3,
	ARG_BITS_128 = 1 << 4,
	ARG_BITS_256 = 1 << 5,
	ARG_BITS_512 = 1 << 6,
	ARG_BITS_80 = 1 << 7,
	ARG_BITS_5 = 1 << 8,
	ARG_BITS_12 = 1 << 9,
	ARG_BITS_20 = 1 << 10,
} AsmArgBits;

typedef enum
{
	ASM_ARG_REG,
	ASM_ARG_ADDR,
	ASM_ARG_REGVAR,
	ASM_ARG_ADDROF,
	ASM_ARG_MEMVAR,
	ASM_ARG_VALUE,
	ASM_ARG_INT,
} AsmArgKind;

typedef enum
{
	ASM_SCALE_1,
	ASM_SCALE_2,
	ASM_SCALE_4,
	ASM_SCALE_8,
	ASM_SCALE_SHR,
	ASM_SCALE_SHL,
	ASM_SCALE_ASHL,
	ASM_SCALE_ROR,
	ASM_SCALE_RRX,
} AsmOffsetType;

typedef enum
{
	ASM_REG_INT,
	ASM_REG_FLOAT,
	ASM_REG_IVEC,
	ASM_REF_FVEC,
} AsmRegisterType;

typedef enum
{
	AST_POISONED,
	AST_ASM_STMT,
	AST_ASM_BLOCK_STMT,
	AST_ASM_LABEL,
	AST_ASSERT_STMT,
	AST_BREAK_STMT,
	AST_CASE_STMT,
	AST_COMPOUND_STMT,
	AST_CONTINUE_STMT,
	AST_CT_ASSERT,
	AST_CT_ECHO_STMT,
	AST_CT_ELSE_STMT,
	AST_CT_FOREACH_STMT,
	AST_CT_FOR_STMT,
	AST_CT_IF_STMT,
	AST_CT_SWITCH_STMT,
	AST_DECLARE_STMT,
	AST_DECLS_STMT,
	AST_DEFAULT_STMT,
	AST_DEFER_STMT,
	AST_EXPR_STMT,
	AST_FOR_STMT,
	AST_FOREACH_STMT,
	AST_IF_CATCH_SWITCH_STMT,
	AST_IF_STMT,
	AST_NOP_STMT,
	AST_RETURN_STMT,
	AST_BLOCK_EXIT_STMT,
	AST_SWITCH_STMT,
	AST_NEXTCASE_STMT,
	AST_CONTRACT,
	AST_CONTRACT_FAULT,
} AstKind;

typedef enum
{
	ATOMIC_NONE,
	ATOMIC_UNORDERED,
	ATOMIC_RELAXED,
	ATOMIC_ACQUIRE,
	ATOMIC_RELEASE,
	ATOMIC_ACQUIRE_RELEASE,
	ATOMIC_SEQ_CONSISTENT,
} Atomicity;

typedef enum FLAG_ATTR
{
	ATTR_FUNC = 1 << 0,
	ATTR_GLOBAL = 1 << 1,
	ATTR_LOCAL = 1 << 2,
	ATTR_ENUM = 1 << 3,
	ATTR_STRUCT = 1 << 4,
	ATTR_UNION = 1 << 5,
	ATTR_CONST = 1 << 6,
	ATTR_FAULT = 1 << 7,
	ATTR_DEF = 1 << 8,
	ATTR_MEMBER = 1 << 9,
	ATTR_BITSTRUCT_MEMBER = 1 << 10,
	ATTR_INTERFACE = 1 << 11,
	ATTR_CALL = 1 << 12,
	ATTR_BITSTRUCT = 1 << 13,
	ATTR_MACRO = 1 << 14,
	ATTR_DISTINCT = 1 << 15,
	ATTR_ENUM_VALUE = 1 << 16,
	ATTR_INTERFACE_METHOD = 1 << 17,
	ATTR_PARAM = 1 << 18,
} AttributeDomain;

typedef enum
{
	ATTRIBUTE_ADHOC,
	ATTRIBUTE_ALIGN,
	ATTRIBUTE_BENCHMARK,
	ATTRIBUTE_BIGENDIAN,
	ATTRIBUTE_BUILTIN,
	ATTRIBUTE_CALLCONV,
	ATTRIBUTE_COMPACT,
	ATTRIBUTE_CONST,
	ATTRIBUTE_DEPRECATED,
	ATTRIBUTE_DYNAMIC,
	ATTRIBUTE_EXPORT,
	ATTRIBUTE_EXTERN,
	ATTRIBUTE_FINALIZER,
	ATTRIBUTE_IF,
	ATTRIBUTE_INLINE,
	ATTRIBUTE_INIT,
	ATTRIBUTE_LINK,
	ATTRIBUTE_LITTLEENDIAN,
	ATTRIBUTE_LOCAL,
	ATTRIBUTE_MAYDISCARD,
	ATTRIBUTE_NAKED,
	ATTRIBUTE_NOALIAS,
	ATTRIBUTE_NODISCARD,
	ATTRIBUTE_NOINIT,
	ATTRIBUTE_NOINLINE,
	ATTRIBUTE_NOPADDING,
	ATTRIBUTE_NORECURSE,
	ATTRIBUTE_NORETURN,
	ATTRIBUTE_NOSANITIZE,
	ATTRIBUTE_NOSTRIP,
	ATTRIBUTE_OBFUSCATE,
	ATTRIBUTE_OPERATOR,
	ATTRIBUTE_OPTIONAL,
	ATTRIBUTE_OVERLAP,
	ATTRIBUTE_PACKED,
	ATTRIBUTE_PRIVATE,
	ATTRIBUTE_PUBLIC,
	ATTRIBUTE_PURE,
	ATTRIBUTE_REFLECT,
	ATTRIBUTE_SAFEMACRO,
	ATTRIBUTE_SECTION,
	ATTRIBUTE_TAG,
	ATTRIBUTE_TEST,
	ATTRIBUTE_UNUSED,
	ATTRIBUTE_USED,
	ATTRIBUTE_WASM,
	ATTRIBUTE_WEAK,
	ATTRIBUTE_WINMAIN,
	ATTRIBUTE_NONE,
	NUMBER_OF_ATTRIBUTES = ATTRIBUTE_NONE,
} AttributeType;

typedef enum
{
	BINARYOP_ERROR,
	BINARYOP_MULT,
	BINARYOP_SUB,
	BINARYOP_ADD,
	BINARYOP_DIV,
	BINARYOP_MOD,
	BINARYOP_SHR,
	BINARYOP_SHL,
	BINARYOP_BIT_OR,
	BINARYOP_BIT_XOR,
	BINARYOP_BIT_AND,
	BINARYOP_AND,
	BINARYOP_OR,
	BINARYOP_ELSE,
	BINARYOP_CT_AND,
	BINARYOP_CT_OR,
	BINARYOP_CT_CONCAT,
	// Don't change the ordering for GT to EQ or things will break
	BINARYOP_GT,
	BINARYOP_GE,
	BINARYOP_LT,
	BINARYOP_LE,
	BINARYOP_NE,
	BINARYOP_EQ,
	// Vec comparisons
	BINARYOP_VEC_GT,
	BINARYOP_VEC_GE,
	BINARYOP_VEC_LT,
	BINARYOP_VEC_LE,
	BINARYOP_VEC_NE,
	BINARYOP_VEC_EQ,
	// Only "assign" BINOPS after this point
	BINARYOP_ASSIGN,
	BINARYOP_ADD_ASSIGN,
	BINARYOP_BIT_AND_ASSIGN,
	BINARYOP_BIT_OR_ASSIGN,
	BINARYOP_BIT_XOR_ASSIGN,
	BINARYOP_DIV_ASSIGN,
	BINARYOP_MOD_ASSIGN,
	BINARYOP_MULT_ASSIGN,
	BINARYOP_SHR_ASSIGN,
	BINARYOP_SHL_ASSIGN,
	BINARYOP_SUB_ASSIGN,
	BINARYOP_LAST = BINARYOP_SUB_ASSIGN
} BinaryOp;

typedef enum
{
	BIT1,
	BITS8,
	BITS16,
	BITS32,
	BITS64,
	BITS128,
	BITS256,
	BITSIZES_LEN
} BitSizes;

typedef enum BoolErr__
{
	BOOL_ERR = -1,
	BOOL_FALSE = 0,
	BOOL_TRUE = 1,
} BoolErr;

typedef enum
{
	ACCESS_TYPEOFANY,
	ACCESS_TYPEOFANYFAULT,
	ACCESS_ENUMNAME,
	ACCESS_FAULTNAME,
	ACCESS_FAULTORDINAL,
} BuiltinAccessKind;

typedef enum
{
	BUILTIN_DEF_DATE,
	BUILTIN_DEF_FILE,
	BUILTIN_DEF_FILEPATH,
	BUILTIN_DEF_FUNC,
	BUILTIN_DEF_FUNCTION,
	BUILTIN_DEF_LINE,
	BUILTIN_DEF_LINE_RAW,
	BUILTIN_DEF_MODULE,
	BUILTIN_DEF_BENCHMARK_NAMES,
	BUILTIN_DEF_BENCHMARK_FNS,
	BUILTIN_DEF_TEST_NAMES,
	BUILTIN_DEF_TEST_FNS,
	BUILTIN_DEF_TIME,
	BUILTIN_DEF_NONE,
	NUMBER_OF_BUILTIN_DEFINES = BUILTIN_DEF_NONE
} BuiltinDefine;

typedef enum
{
	BUILTIN_ABS,
	BUILTIN_ANY_MAKE,
	BUILTIN_ATOMIC_LOAD,
	BUILTIN_ATOMIC_STORE,
	BUILTIN_ATOMIC_FETCH_EXCHANGE,
	BUILTIN_ATOMIC_FETCH_ADD,
	BUILTIN_ATOMIC_FETCH_SUB,
	BUILTIN_ATOMIC_FETCH_AND,
	BUILTIN_ATOMIC_FETCH_NAND,
	BUILTIN_ATOMIC_FETCH_OR,
	BUILTIN_ATOMIC_FETCH_XOR,
	BUILTIN_ATOMIC_FETCH_MAX,
	BUILTIN_ATOMIC_FETCH_MIN,
	BUILTIN_ATOMIC_FETCH_INC_WRAP,
	BUILTIN_ATOMIC_FETCH_DEC_WRAP,
	BUILTIN_BITREVERSE,
	BUILTIN_BREAKPOINT,
	BUILTIN_BSWAP,
	BUILTIN_CEIL,
	BUILTIN_COMPARE_EXCHANGE,
	BUILTIN_COPYSIGN,
	BUILTIN_COS,
	BUILTIN_CTLZ,
	BUILTIN_CTTZ,
	BUILTIN_EXACT_ADD,
	BUILTIN_EXACT_DIV,
	BUILTIN_EXACT_MOD,
	BUILTIN_EXACT_MUL,
	BUILTIN_EXACT_NEG,
	BUILTIN_EXACT_SUB,
	BUILTIN_EXP,
	BUILTIN_EXP2,
	BUILTIN_EXPECT,
	BUILTIN_EXPECT_WITH_PROBABILITY,
	BUILTIN_FLOOR,
	BUILTIN_FMA,
	BUILTIN_FMULADD,
	BUILTIN_FRAMEADDRESS,
	BUILTIN_FSHL,
	BUILTIN_FSHR,
	BUILTIN_GATHER,
	BUILTIN_GET_ROUNDING_MODE,
	BUILTIN_LOG,
	BUILTIN_LOG10,
	BUILTIN_LOG2,
	BUILTIN_MASKED_LOAD,
	BUILTIN_MASKED_STORE,
	BUILTIN_MAX,
	BUILTIN_MEMCOPY,
	BUILTIN_MEMCOPY_INLINE,
	BUILTIN_MEMMOVE,
	BUILTIN_MEMSET,
	BUILTIN_MEMSET_INLINE,
	BUILTIN_MIN,
	BUILTIN_NEARBYINT,
	BUILTIN_OVERFLOW_ADD,
	BUILTIN_OVERFLOW_MUL,
	BUILTIN_OVERFLOW_SUB,
	BUILTIN_POPCOUNT,
	BUILTIN_POW,
	BUILTIN_POW_INT,
	BUILTIN_PREFETCH,
	BUILTIN_REDUCE_ADD,
	BUILTIN_REDUCE_AND,
	BUILTIN_REDUCE_FADD,
	BUILTIN_REDUCE_FMUL,
	BUILTIN_REDUCE_MAX,
	BUILTIN_REDUCE_MIN,
	BUILTIN_REDUCE_MUL,
	BUILTIN_REDUCE_OR,
	BUILTIN_REDUCE_XOR,
	BUILTIN_REVERSE,
	BUILTIN_RETURNADDRESS,
	BUILTIN_RINT,
	BUILTIN_ROUND,
	BUILTIN_ROUNDEVEN,
	BUILTIN_SAT_ADD,
	BUILTIN_SAT_SHL,
	BUILTIN_SAT_SUB,
	BUILTIN_SCATTER,
	BUILTIN_SELECT,
	BUILTIN_SET_ROUNDING_MODE,
	BUILTIN_STR_HASH,
	BUILTIN_STR_UPPER,
	BUILTIN_STR_LOWER,
	BUILTIN_STR_FIND,
	BUILTIN_SWIZZLE,
	BUILTIN_SWIZZLE2,
	BUILTIN_SIN,
	BUILTIN_SQRT,
	BUILTIN_SYSCALL,
	BUILTIN_SYSCLOCK,
	BUILTIN_TRAP,
	BUILTIN_TRUNC,
	BUILTIN_UNALIGNED_LOAD,
	BUILTIN_UNALIGNED_STORE,
	BUILTIN_UNREACHABLE,
	BUILTIN_VECCOMPLT,
	BUILTIN_VECCOMPLE,
	BUILTIN_VECCOMPGT,
	BUILTIN_VECCOMPGE,
	BUILTIN_VECCOMPEQ,
	BUILTIN_VECCOMPNE,
	BUILTIN_VOLATILE_LOAD,
	BUILTIN_VOLATILE_STORE,
	BUILTIN_WASM_MEMORY_SIZE,
	BUILTIN_WASM_MEMORY_GROW,
	BUILTIN_NONE,
	NUMBER_OF_BUILTINS = BUILTIN_NONE,

// Disabled for now!
	BUILTIN_LLRINT,
	BUILTIN_LLROUND,
	BUILTIN_LRINT,
	BUILTIN_LROUND,
} BuiltinFunction;

typedef enum
{
	CALL_C,
	CALL_X64_VECTOR,
	CALL_AAPCS,
	CALL_AAPCS_VFP,
} CallABI;

typedef enum
{
	CALL_ENV_GLOBAL_INIT,
	CALL_ENV_FUNCTION,
	CALL_ENV_FUNCTION_STATIC,
	CALL_ENV_ATTR,
} CallEnvKind;

typedef enum
{
	CMP_LT = -1,
	CMP_EQ = 0,
	CMP_GT = 1,
} CmpRes;

typedef enum
{
	COND_MISSING = -1,
	COND_TRUE = 1,
	COND_FALSE = 0,
} CondResult;

typedef enum
{
	COND_TYPE_UNWRAP_BOOL,
	COND_TYPE_UNWRAP,
	COND_TYPE_EVALTYPE_VALUE,
} CondType;


typedef enum
{
	CONST_INIT_ZERO,
	CONST_INIT_STRUCT,
	CONST_INIT_UNION,
	CONST_INIT_VALUE,
	CONST_INIT_ARRAY,
	CONST_INIT_ARRAY_FULL,
	CONST_INIT_ARRAY_VALUE,
} ConstInitType;

typedef enum
{
	CONST_FLOAT,
	CONST_INTEGER,
	CONST_BOOL,
	CONST_ENUM,
	CONST_ERR,
	CONST_BYTES,
	CONST_STRING,
	CONST_POINTER,
	CONST_TYPEID,
	CONST_SLICE,
	CONST_INITIALIZER,
	CONST_UNTYPED_LIST,
	CONST_REF,
	CONST_MEMBER,
} ConstKind;

typedef enum
{
	CONTRACT_UNKNOWN,
	CONTRACT_COMMENT,
	CONTRACT_PURE,
	CONTRACT_REQUIRE,
	CONTRACT_PARAM,
	CONTRACT_OPTIONALS,
	CONTRACT_ENSURE,
} ContractKind;

typedef enum
{
	CONV_NO = -1,
	CONV_VOID = 0,
	CONV_WILDCARD,
	CONV_BOOL,
	CONV_INT,
	CONV_FLOAT,
	CONV_POINTER,
	CONV_SLICE,
	CONV_VECTOR,
	CONV_BITSTRUCT,
	CONV_DISTINCT,
	CONV_ARRAY,
	CONV_STRUCT,
	CONV_UNION,
	CONV_ANY,
	CONV_INTERFACE,
	CONV_FAULT,
	CONV_ENUM,
	CONV_FUNC,
	CONV_TYPEID,
	CONV_ANYFAULT,
	CONV_VOIDPTR,
	CONV_VAPTR,
	CONV_INFERRED,
	CONV_UNTYPED_LIST,
	CONV_LAST = CONV_UNTYPED_LIST
} ConvGroup;


typedef enum
{
	CTYPE_SHORT,
	CTYPE_INT,
	CTYPE_LONG,
	CTYPE_LONG_LONG
} CType;

typedef enum
{
	DECL_POISONED = 0,
	DECL_ATTRIBUTE,
	DECL_BITSTRUCT,
	DECL_BODYPARAM,
	DECL_CT_ASSERT,
	DECL_CT_ECHO,
	DECL_CT_EXEC,
	DECL_CT_INCLUDE,
	DECL_DECLARRAY,
	DECL_DEFINE,
	DECL_DISTINCT,
	DECL_ENUM,
	DECL_ENUM_CONSTANT,
	DECL_ERASED,
	DECL_FAULT,
	DECL_FAULTVALUE,
	DECL_FNTYPE,
	DECL_FUNC,
	DECL_GLOBALS,
	DECL_IMPORT,
	DECL_LABEL,
	DECL_MACRO,
	DECL_INTERFACE,
	DECL_STRUCT,
	DECL_TYPEDEF,
	DECL_UNION,
	DECL_VAR,
} DeclKind;

typedef enum
{
	DEFINE_IDENT_ALIAS,
	DEFINE_IDENT_GENERIC,
} DefineType;

typedef enum
{
	DESIGNATOR_FIELD,
	DESIGNATOR_ARRAY,
	DESIGNATOR_RANGE
} DesignatorType;

typedef enum
{
	ENV_TYPE_UNKNOWN,
	ENV_TYPE_GNU,
	ENV_TYPE_GNUABIN32,
	ENV_TYPE_GNUABI64,
	ENV_TYPE_GNUEABI,
	ENV_TYPE_GNUEABIHF,
	ENV_TYPE_GNUX32,
	ENV_TYPE_CODE16,
	ENV_TYPE_EABI,
	ENV_TYPE_EABIHF,
	ENV_TYPE_ELFV1,
	ENV_TYPE_ELFV2,
	ENV_TYPE_ANDROID,
	ENV_TYPE_MUSL,
	ENV_TYPE_MUSLEABI,
	ENV_TYPE_MUSLEABIHF,
	ENV_TYPE_MSVC,
	ENV_TYPE_ITANIUM,
	ENV_TYPE_CYGNUS,
	ENV_TYPE_CORECLR,
	ENV_TYPE_SIMULATOR,
	ENV_TYPE_MACABI,
	ENV_TYPE_LAST = ENV_TYPE_MACABI
} EnvironmentType;

typedef enum
{
	EXPR_ACCESS_RESOLVED,
	EXPR_ACCESS_UNRESOLVED,
	EXPR_ANYSWITCH,
	EXPR_ASM,
	EXPR_BENCHMARK_HOOK,
	EXPR_BINARY,
	EXPR_BITACCESS,
	EXPR_BITASSIGN,
	EXPR_BUILTIN,
	EXPR_BUILTIN_ACCESS,
	EXPR_CALL,
	EXPR_CAST,
	EXPR_CATCH_UNRESOLVED,
	EXPR_CATCH,
	EXPR_COMPILER_CONST,
	EXPR_COMPOUND_LITERAL,
	EXPR_COND,
	EXPR_CONST,
	EXPR_TYPECALL,
	EXPR_CT_AND_OR,
	EXPR_CT_ARG,
	EXPR_CT_APPEND,
	EXPR_CT_CALL,
	EXPR_CT_CASTABLE,
	EXPR_CT_CONCAT,
	EXPR_CT_DEFINED,
	EXPR_CT_EVAL,
	EXPR_CT_IDENT,
	EXPR_CT_IS_CONST,
	EXPR_CT_SUBSCRIPT,
	EXPR_DECL,
	EXPR_DEFAULT_ARG,
	EXPR_DESIGNATED_INITIALIZER_LIST,
	EXPR_DESIGNATOR,
	EXPR_DISCARD,
	EXPR_EMBED,
	EXPR_VECTOR_TO_ARRAY,
	EXPR_SLICE_TO_VEC_ARRAY,
	EXPR_SCALAR_TO_VECTOR,
	EXPR_EXPRESSION_LIST,
	EXPR_EXPR_BLOCK,
	EXPR_FORCE_UNWRAP,
	EXPR_FLOAT_TO_INT,
	EXPR_GENERIC_IDENT,
	EXPR_HASH_IDENT,
	EXPR_IDENTIFIER,
	EXPR_INITIALIZER_LIST,
	EXPR_INT_TO_FLOAT,
	EXPR_INT_TO_PTR,
	EXPR_PTR_TO_INT,
	EXPR_ANYFAULT_TO_FAULT,
	EXPR_LAMBDA,
	EXPR_LAST_FAULT,
	EXPR_MACRO_BLOCK,
	EXPR_MACRO_BODY,
	EXPR_MACRO_BODY_EXPANSION,
	EXPR_MAKE_ANY,
	EXPR_MAKE_SLICE,
	EXPR_MEMBER_GET,
	EXPR_NAMED_ARGUMENT,
	EXPR_NOP,
	EXPR_OPERATOR_CHARS,
	EXPR_OPTIONAL,
	EXPR_ENUM_FROM_ORD,
	EXPR_OTHER_CONTEXT,
	EXPR_POINTER_OFFSET,
	EXPR_ADDR_CONVERSION,
	EXPR_POISONED,
	EXPR_PTR_ACCESS,
	EXPR_POST_UNARY,
	EXPR_RETHROW,
	EXPR_RETVAL,
	EXPR_RVALUE,
	EXPR_RECAST,
	EXPR_SLICE,
	EXPR_SLICE_LEN,
	EXPR_SLICE_ASSIGN,
	EXPR_SLICE_COPY,
	EXPR_SPLAT,
	EXPR_STRINGIFY,
	EXPR_SUBSCRIPT,
	EXPR_SUBSCRIPT_ADDR,
	EXPR_SUBSCRIPT_ASSIGN,
	EXPR_SWIZZLE,
	EXPR_TERNARY,
	EXPR_TEST_HOOK,
	EXPR_TRY,
	EXPR_TRY_UNRESOLVED,
	EXPR_TRY_UNWRAP_CHAIN,
	EXPR_TYPEID,
	EXPR_TYPEID_INFO,
	EXPR_TYPEINFO,
	EXPR_UNRESOLVED_IDENTIFIER,
	EXPR_UNARY,
	EXPR_VASPLAT,
	EXPR_VECTOR_FROM_ARRAY,
	EXPR_EXT_TRUNC,
	EXPR_INT_TO_BOOL,
	EXPR_LAST = EXPR_VASPLAT
} ExprKind;

typedef enum
{
	FLOAT_ABI_NONE,
	FLOAT_ABI_SOFT,
	FLOAT_ABI_HARD,
} FloatABI;

typedef enum
{
	INOUT_ANY,
	INOUT_IN,
	INOUT_OUT,
	INOUT_INOUT,
} InOutModifier;

typedef enum
{
	INTROSPECT_TYPE_VOID = 0,
	INTROSPECT_TYPE_BOOL = 1,
	INTROSPECT_TYPE_SIGNED_INT = 2,
	INTROSPECT_TYPE_UNSIGNED_INT = 3,
	INTROSPECT_TYPE_FLOAT = 4,
	INTROSPECT_TYPE_TYPEID = 5,
	INTROSPECT_TYPE_ANYFAULT = 6,
	INTROSPECT_TYPE_ANY = 7,
	INTROSPECT_TYPE_ENUM = 8,
	INTROSPECT_TYPE_FAULT = 9,
	INTROSPECT_TYPE_STRUCT = 10,
	INTROSPECT_TYPE_UNION = 11,
	INTROSPECT_TYPE_BITSTRUCT = 12,
	INTROSPECT_TYPE_FUNC = 13,
	INTROSPECT_TYPE_OPTIONAL = 14,
	INTROSPECT_TYPE_ARRAY = 15,
	INTROSPECT_TYPE_SLICE = 16,
	INTROSPECT_TYPE_VECTOR = 17,
	INTROSPECT_TYPE_DISTINCT = 18,
	INTROSPECT_TYPE_POINTER = 19,
	INTROSPECT_TYPE_INTERFACE = 20,
} IntrospectType;

typedef enum
{
	LEX_NORMAL,
	LEX_CONTRACTS,
} LexMode;

typedef enum
{
	LINKER_LINK_EXE,
	LINKER_LD,
	LINKER_LD64,
	LINKER_WASM,
	LINKER_CC,
	LINKER_UNKNOWN
} Linker;

typedef enum
{
	MAIN_TYPE_ERROR,
	MAIN_TYPE_RAW,
	MAIN_TYPE_NO_ARGS,
	MAIN_TYPE_ARGS,
	MAIN_TYPE_WIN,
} MainType;

typedef enum
{
	METHOD_SEARCH_SUBMODULE_CURRENT,
	METHOD_SEARCH_IMPORTED,
	METHOD_SEARCH_CURRENT,
	METHOD_SEARCH_PRIVATE_IMPORTED
} MethodSearchType;

typedef enum
{
	OBJ_FORMAT_UNSUPPORTED,
	OBJ_FORMAT_COFF,
	OBJ_FORMAT_GOFF,
	OBJ_FORMAT_ELF,
	OBJ_FORMAT_MACHO,
	OBJ_FORMAT_WASM,
	OBJ_FORMAT_XCOFF,
	OBJ_FORMAT_AOUT,
} ObjectFormatType;

typedef enum
{
	OVERLOAD_ELEMENT_AT = 1,
	OVERLOAD_ELEMENT_REF,
	OVERLOAD_ELEMENT_SET,
	OVERLOAD_LEN,
	OVERLOAD_CONSTRUCT,
} OperatorOverload;

typedef enum
{
	OS_TYPE_UNKNOWN,
	OS_TYPE_NONE,
	OS_TYPE_ANANAS,
	OS_TYPE_CLOUD_ABI,
	OS_TYPE_DRAGON_FLY,
	OS_TYPE_FREE_BSD,
	OS_TYPE_FUCHSIA,
	OS_TYPE_IOS,
	OS_TYPE_KFREEBSD,
	OS_TYPE_LINUX,
	OS_TYPE_PS3,
	OS_TYPE_MACOSX,
	OS_TYPE_NETBSD,
	OS_TYPE_OPENBSD,
	OS_TYPE_SOLARIS,
	OS_TYPE_WIN32,
	OS_TYPE_HAIKU,
	OS_TYPE_MINIX,
	OS_TYPE_RTEMS,
	OS_TYPE_NACL,       // Native Client
	OS_TYPE_CNK,        // BG/P Compute-Node Kernel
	OS_TYPE_AIX,
	OS_TYPE_CUDA,
	OS_TYPE_NVOPENCL,
	OS_TYPE_AMDHSA,
	OS_TYPE_PS4,
	OS_TYPE_ELFIAMCU,
	OS_TYPE_TVOS,
	OS_TYPE_WATCHOS,
	OS_TYPE_MESA3D,
	OS_TYPE_CONTIKI,
	OS_TYPE_AMDPAL,
	OS_TYPE_HERMITCORE,
	OS_TYPE_HURD,
	OS_TYPE_WASI,
	OS_TYPE_EMSCRIPTEN,
	OS_TYPE_LAST = OS_TYPE_EMSCRIPTEN
} OsType;


typedef enum
{
	PREC_NONE,
	PREC_ASSIGNMENT,        // =, *=, /=, %=, +=, etc
	PREC_TERNARY,           // ?: ? ??
	PREC_OR,                // || |||
	PREC_AND,               // && &&&
	PREC_RELATIONAL,        // < > <= >= == !=
	PREC_ADDITIVE,          // + - +++
	PREC_BIT,               // ^ | &
	PREC_SHIFT,             // << >>
	PREC_MULTIPLICATIVE,    // * / %
	PREC_UNARY,             // ! - + ~ * & prefix ++/-- (type)
	PREC_CALL,              // . () [] postfix ++ -- !! !
	PREC_PRIMARY,
} Precedence;

typedef enum
{
	PRINT_TYPE_ERROR,
	PRINT_TYPE_NOTE,
	PRINT_TYPE_WARN
} PrintType;

typedef enum
{
	RESOLVE_NOT_DONE = 0,
	RESOLVE_RUNNING,
	RESOLVE_DONE
} ResolveStatus;

typedef enum
{
	RESOLVE_TYPE_DEFAULT,
	RESOLVE_TYPE_ALLOW_INFER       = 0x01,
	RESOLVE_TYPE_ALLOW_FLEXIBLE    = 0x02,
	RESOLVE_TYPE_NO_CHECK_DISTINCT = 0x04,
	RESOLVE_TYPE_MACRO_METHOD      = RESOLVE_TYPE_ALLOW_INFER | RESOLVE_TYPE_NO_CHECK_DISTINCT,
	RESOLVE_TYPE_FUNC_METHOD       = RESOLVE_TYPE_NO_CHECK_DISTINCT,
} ResolveTypeKind;

typedef enum FLAG_ATTR
{
	SCOPE_NONE = 0,
	SCOPE_ENSURE = 1 << 1,
	SCOPE_ENSURE_MACRO = 1 << 2,
	SCOPE_EXPR_BLOCK = 1 << 3,
	SCOPE_MACRO = 1 << 4,
	SCOPE_COND = 1 << 5,
} ScopeFlags;

typedef enum
{
	STORAGE_ERROR = -1,
	STORAGE_NORMAL = 0,
	STORAGE_VOID,
	STORAGE_COMPILE_TIME,
	STORAGE_WILDCARD,
	STORAGE_UNKNOWN
} StorageType;


typedef enum
{
	TOKEN_INVALID_TOKEN = 0,

	// Single-character tokens.
	TOKEN_AMP,              // &
	TOKEN_AT,               // @
	TOKEN_BANG,             // !
	TOKEN_BIT_NOT,          // ~
	TOKEN_BIT_OR,           // =
	TOKEN_BIT_XOR,          // ^
	TOKEN_COLON,            // :
	TOKEN_COMMA,            // ,
	TOKEN_EOS,              // ;
	TOKEN_EQ,               // =
	TOKEN_GREATER,          // >
	TOKEN_DIV,              // /
	TOKEN_DOLLAR,           // $
	TOKEN_DOT,              // .
	TOKEN_HASH,             // #
	TOKEN_LESS,             // <
	TOKEN_LBRACE,           // {
	TOKEN_LBRACKET,         // [
	TOKEN_LPAREN,           // (
	TOKEN_MINUS,            // -
	TOKEN_MOD,              // %
	TOKEN_PLUS,             // +
	TOKEN_QUESTION,         // ?
	TOKEN_RBRACE,           // }
	TOKEN_RBRACKET,         // ]
	TOKEN_RPAREN,           // )
	TOKEN_STAR,             // *
	TOKEN_UNDERSCORE,       // _

	// two character tokens.
	TOKEN_AND,              // &&
	TOKEN_ARROW,            // -> // Not used but reserved
	TOKEN_BANGBANG,         // !!
	TOKEN_BIT_AND_ASSIGN,   // &=
	TOKEN_BIT_OR_ASSIGN,    // |=
	TOKEN_BIT_XOR_ASSIGN,   // ^=
	TOKEN_DIV_ASSIGN,       // /=
	TOKEN_DOTDOT,           // ..
	TOKEN_BUILTIN,          // $$
	TOKEN_ELVIS,            // ?:
	TOKEN_EQEQ,             // ==
	TOKEN_GREATER_EQ,       // >=
	TOKEN_IMPLIES,          // =>
	TOKEN_LESS_EQ,          // <=
	TOKEN_LBRAPIPE,         // {|
	TOKEN_LGENPAR,          // (<
	TOKEN_LVEC,             // [<
	TOKEN_MINUS_ASSIGN,     // -=
	TOKEN_MINUSMINUS,       // --
	TOKEN_MOD_ASSIGN,       // %=
	TOKEN_MULT_ASSIGN,      // *=
	TOKEN_NOT_EQUAL,        // !=
	TOKEN_OR,               // ||
	TOKEN_PLUS_ASSIGN,      // +=
	TOKEN_PLUSPLUS,         // ++
	TOKEN_RBRAPIPE,         // |}
	TOKEN_RGENPAR,          // >)
	TOKEN_RVEC,             // >]
	TOKEN_QUESTQUEST,       // ??
	TOKEN_SCOPE,            // ::
	TOKEN_SHL,              // <<
	TOKEN_SHR,              // >>

	// Three or more
	TOKEN_ELLIPSIS,         // ...
	TOKEN_SHL_ASSIGN,       // <<=
	TOKEN_SHR_ASSIGN,       // >>=
	TOKEN_CT_AND,           // &&&
	TOKEN_CT_CONCAT,        // +++
	TOKEN_CT_OR,            // |||
	// Literals.
	TOKEN_IDENT,            // Any normal ident.
	TOKEN_CONST_IDENT,      // Any purely uppercase ident,
	TOKEN_TYPE_IDENT,       // Any ident on the format FooBar or __FooBar

	// We want to parse $foo separately,
	// otherwise we allow things like "$ foo" which would be pretty bad.
	TOKEN_CT_IDENT,         // $foobar
	TOKEN_CT_CONST_IDENT,   // $FOOBAR
	TOKEN_CT_TYPE_IDENT,    // $Foobar

	// We want to parse #foo separately.
	TOKEN_HASH_IDENT,       // #foobar
	TOKEN_HASH_CONST_IDENT, // #FOOBAR
	TOKEN_HASH_TYPE_IDENT,  // #Foobar

	TOKEN_AT_IDENT,         // @macro
	TOKEN_AT_CONST_IDENT,   // @MACRO
	TOKEN_AT_TYPE_IDENT,    // @Macro

	TOKEN_STRING,           // "Teststring"
	TOKEN_INTEGER,          // 123 0x23 0b10010 0o327
	TOKEN_CHAR_LITERAL,        // 'a' 'FO' 'BARS' '\u1232'
	TOKEN_REAL,             // 0x23.2p-2a 43.23e23
	TOKEN_BYTES,            // Base64 or Hex

	TOKEN_DOC_COMMENT,      // Doc Comment start

	// Basic types names
	TOKEN_VOID,
	TOKEN_FIRST_KEYWORD = TOKEN_VOID,
	TOKEN_BOOL,
	TOKEN_CHAR,
	TOKEN_DOUBLE,
	TOKEN_FLOAT,
	TOKEN_FLOAT16,
	TOKEN_BFLOAT,
	TOKEN_INT128,
	TOKEN_ICHAR,
	TOKEN_INT,
	TOKEN_IPTR,
	TOKEN_ISZ,
	TOKEN_LONG,
	TOKEN_SHORT,
	TOKEN_UINT128,
	TOKEN_UINT,
	TOKEN_ULONG,
	TOKEN_UPTR,
	TOKEN_USHORT,
	TOKEN_UCHAR,
	TOKEN_USZ,
	TOKEN_FLOAT128,
	TOKEN_ANY,
	TOKEN_ANYFAULT,
	TOKEN_TYPEID,

	// Keywords
	TOKEN_ASSERT,
	TOKEN_ASM,
	TOKEN_BITSTRUCT,
	TOKEN_BREAK,
	TOKEN_CASE,
	TOKEN_CATCH,
	TOKEN_CONST,
	TOKEN_CONTINUE,
	TOKEN_DEF,
	TOKEN_DEFAULT,
	TOKEN_DEFER,
	TOKEN_DISTINCT,
	TOKEN_DO,
	TOKEN_ELSE,
	TOKEN_ENUM,
	TOKEN_EXTERN,
	TOKEN_FALSE,
	TOKEN_FAULT,
	TOKEN_FOR,
	TOKEN_FOREACH,
	TOKEN_FOREACH_R,
	TOKEN_FN,
	TOKEN_TLOCAL,
	TOKEN_IF,
	TOKEN_INLINE,
	TOKEN_IMPORT,
	TOKEN_MACRO,
	TOKEN_MODULE,
	TOKEN_NEXTCASE,
	TOKEN_NULL,
	TOKEN_INTERFACE,
	TOKEN_RETURN,
	TOKEN_STATIC,
	TOKEN_STRUCT,
	TOKEN_SWITCH,
	TOKEN_TRUE,
	TOKEN_TRY,
	TOKEN_UNION,
	TOKEN_VAR,
	TOKEN_WHILE,
	TOKEN_LAST_NON_CT_KEYWORD = TOKEN_WHILE,

	TOKEN_CT_ALIGNOF,           // $alignof
	TOKEN_CT_ANDFN,             // $and
	TOKEN_CT_APPEND,            // $append
	TOKEN_CT_ASSERT,            // $assert
	TOKEN_CT_ASSIGNABLE,        // $assignable
	TOKEN_CT_CASE,              // $case
	TOKEN_CT_CONCATFN,          // $concat
	TOKEN_CT_DEFAULT,           // $default
	TOKEN_CT_DEFINED,           // $defined
	TOKEN_CT_ECHO,              // $echo
	TOKEN_CT_ELSE,              // $else
	TOKEN_CT_EMBED,             // $embed
	TOKEN_CT_ENDFOR,            // $endfor
	TOKEN_CT_ENDFOREACH,        // $endforeach
	TOKEN_CT_ENDIF,             // $endif
	TOKEN_CT_ENDSWITCH,         // $endswitch
	TOKEN_CT_EVAL,              // $eval
	TOKEN_CT_EVALTYPE,          // $evaltype
	TOKEN_CT_ERROR,             // $error
	TOKEN_CT_EXEC,              // $exec
	TOKEN_CT_EXTNAMEOF,         // $extnameof
	TOKEN_CT_FEATURE,           // $feature
	TOKEN_CT_FOR,               // $for
	TOKEN_CT_FOREACH,           // $foreach
	TOKEN_CT_IF,                // $if
	TOKEN_CT_INCLUDE,           // $include
	TOKEN_CT_IS_CONST,          // $is_const
	TOKEN_CT_NAMEOF,            // $nameof
	TOKEN_CT_OFFSETOF,          // $offsetof
	TOKEN_CT_ORFN,              // $or
	TOKEN_CT_QNAMEOF,           // $qnameof
	TOKEN_CT_SIZEOF,            // $sizeof
	TOKEN_CT_STRINGIFY,         // $stringify
	TOKEN_CT_SWITCH,            // $switch
	TOKEN_CT_TYPEFROM,          // $typefrom
	TOKEN_CT_TYPEOF,            // $typeof
	TOKEN_CT_VACOUNT,           // $vacount
	TOKEN_CT_VATYPE,            // $vatype
	TOKEN_CT_VACONST,           // $vaconst,
	TOKEN_CT_VAREF,             // $varef,
	TOKEN_CT_VAARG,             // $vaarg,
	TOKEN_CT_VAEXPR,            // $vaexpr,
	TOKEN_CT_VASPLAT,           // $vasplat,
	TOKEN_LAST_KEYWORD = TOKEN_CT_VASPLAT,
	TOKEN_DOCS_START,       // <*
	TOKEN_DOCS_END,         // *>
	TOKEN_DOCS_EOL,

	TOKEN_EOF,              // \n - SHOULD ALWAYS BE THE LAST TOKEN.

	TOKEN_LAST = TOKEN_EOF,
} TokenType;

typedef enum
{
	TYPE_MISMATCH = 0,
	TYPE_SAME = 1,
	TYPE_SAME_INT_SIZE = 2,
	TYPE_ALIGNMENT_INCREASE = 3,
	TYPE_ERROR = -1,
} TypeCmpResult;

typedef enum
{
	TYPEID_INFO_KIND,
	TYPEID_INFO_PARENTOF,
	TYPEID_INFO_INNER,
	TYPEID_INFO_LEN,
	TYPEID_INFO_SIZEOF,
	TYPEID_INFO_NAMES,
} TypeIdInfoKind;

typedef enum
{
	TYPE_COMPRESSED_NONE = 0,
	TYPE_COMPRESSED_PTR = 1,
	TYPE_COMPRESSED_SUB = 2,
	TYPE_COMPRESSED_SUBPTR = 3,
	TYPE_COMPRESSED_PTRPTR = 4,
	TYPE_COMPRESSED_PTRSUB = 5,
	TYPE_COMPRESSED_SUBSUB = 6,
} TypeInfoCompressedKind;

typedef enum
{
	TYPE_INFO_POISON,
	TYPE_INFO_IDENTIFIER,
	TYPE_INFO_CT_IDENTIFIER,
	TYPE_INFO_TYPEOF,
	TYPE_INFO_VATYPE,
	TYPE_INFO_EVALTYPE,
	TYPE_INFO_TYPEFROM,
	TYPE_INFO_ARRAY,
	TYPE_INFO_VECTOR,
	TYPE_INFO_INFERRED_ARRAY,
	TYPE_INFO_INFERRED_VECTOR,
	TYPE_INFO_SLICE,
	TYPE_INFO_POINTER,
	TYPE_INFO_GENERIC,
} TypeInfoKind;

// Note that ordering matters here. If ordering is changed,
// So must type_find_max_type and friends.
// The reason is that for binary expressions we can simplify
// by knowing the type_kind of left <= type kind of right
typedef enum
{
	TYPE_POISONED,
	TYPE_VOID,
	TYPE_BOOL,
	TYPE_I8,
	TYPE_INTEGER_FIRST = TYPE_I8,
	TYPE_NUM_FIRST = TYPE_INTEGER_FIRST,
	TYPE_INT_FIRST = TYPE_INTEGER_FIRST,
	TYPE_I16,
	TYPE_I32,
	TYPE_I64,
	TYPE_I128,
	TYPE_INT_LAST = TYPE_I128,
	TYPE_U8,
	TYPE_UINT_FIRST = TYPE_U8,
	TYPE_U16,
	TYPE_U32,
	TYPE_U64,
	TYPE_U128,
	TYPE_UINT_LAST = TYPE_U128,
	TYPE_INTEGER_LAST = TYPE_U128,
	TYPE_F16,
	TYPE_FLOAT_FIRST = TYPE_F16,
	TYPE_BF16,
	TYPE_F32,
	TYPE_F64,
	TYPE_F128,
	TYPE_FLOAT_LAST = TYPE_F128,
	TYPE_NUM_LAST = TYPE_FLOAT_LAST,
	TYPE_DISTINCT,
	TYPE_ANY,
	TYPE_INTERFACE,
	TYPE_ANYFAULT,
	TYPE_TYPEID,
	TYPE_FUNC_PTR,
	TYPE_POINTER,
	TYPE_ENUM,
	TYPE_FUNC_RAW,
	TYPE_STRUCT,
	TYPE_UNION,
	TYPE_BITSTRUCT,
	TYPE_FAULTTYPE,
	TYPE_TYPEDEF,
	TYPE_UNTYPED_LIST,
	TYPE_SLICE,
	TYPE_ARRAY,
	TYPE_FIRST_ARRAYLIKE = TYPE_ARRAY,
	TYPE_FLEXIBLE_ARRAY,
	TYPE_INFERRED_ARRAY,
	TYPE_VECTOR,
	TYPE_INFERRED_VECTOR,
	TYPE_LAST_ARRAYLIKE = TYPE_INFERRED_VECTOR,
	TYPE_OPTIONAL,
	TYPE_WILDCARD,
	TYPE_TYPEINFO,
	TYPE_MEMBER,
	TYPE_LAST = TYPE_MEMBER
} TypeKind;

typedef enum
{
	TYPE_PROPERTY_ALIGNOF,
	TYPE_PROPERTY_ASSOCIATED,
	TYPE_PROPERTY_ELEMENTS,
	TYPE_PROPERTY_EXTNAMEOF,
	TYPE_PROPERTY_FROM_ORDINAL,
	TYPE_PROPERTY_GET,
	TYPE_PROPERTY_INF,
	TYPE_PROPERTY_IS_EQ,
	TYPE_PROPERTY_IS_ORDERED,
	TYPE_PROPERTY_IS_SUBSTRUCT,
	TYPE_PROPERTY_LEN,
	TYPE_PROPERTY_MAX,
	TYPE_PROPERTY_MEMBERSOF,
	TYPE_PROPERTY_METHODSOF,
	TYPE_PROPERTY_MIN,
	TYPE_PROPERTY_NAN,
	TYPE_PROPERTY_INNER,
	TYPE_PROPERTY_KINDOF,
	TYPE_PROPERTY_NAMES,
	TYPE_PROPERTY_NAMEOF,
	TYPE_PROPERTY_PARAMS,
	TYPE_PROPERTY_PARAMSOF,
	TYPE_PROPERTY_PARENTOF,
	TYPE_PROPERTY_QNAMEOF,
	TYPE_PROPERTY_RETURNS,
	TYPE_PROPERTY_SIZEOF,
	TYPE_PROPERTY_TAGOF,
	TYPE_PROPERTY_HAS_TAGOF,
	TYPE_PROPERTY_VALUES,
	TYPE_PROPERTY_NONE,
	NUMBER_OF_TYPE_PROPERTIES = TYPE_PROPERTY_NONE
} TypeProperty;

typedef enum
{
	UNARYOP_ERROR,
	UNARYOP_DEREF,
	UNARYOP_ADDR,
	UNARYOP_NEG,
	UNARYOP_PLUS,
	UNARYOP_BITNEG,
	UNARYOP_NOT,
	UNARYOP_INC,
	UNARYOP_DEC,
	UNARYOP_TADDR,
} UnaryOp;

typedef enum
{
	VARDECL_CONST = 0,
	VARDECL_GLOBAL,
	VARDECL_LOCAL,
	VARDECL_PARAM,
	VARDECL_MEMBER,
	VARDECL_BITMEMBER,
	VARDECL_PARAM_REF,
	VARDECL_PARAM_EXPR,
	VARDECL_UNWRAPPED,
	VARDECL_ERASE,
	VARDECL_REWRAPPED,
	VARDECL_PARAM_CT,
	VARDECL_PARAM_CT_TYPE,
	VARDECL_LOCAL_CT,
	VARDECL_LOCAL_CT_TYPE,
	VARDECL_FIRST_CT = VARDECL_PARAM_CT,
	VARDECL_LAST_CT = VARDECL_LOCAL_CT_TYPE,
} VarDeclKind;

typedef enum
{
	VARIADIC_NONE,
	VARIADIC_TYPED,
	VARIADIC_ANY,
	VARIADIC_RAW,
} Variadic;

typedef enum
{
	VENDOR_UNKNOWN,
	VENDOR_APPLE,
	VENDOR_PC,
	VENDOR_SCEI,
	VENDOR_BGP,
	VENDOR_BGQ,
	VENDOR_FREESCALE,
	VENDOR_IBM,
	VENDOR_IMAGINATION_TECHNOLOGIES,
	VENDOR_MIPS_TECHNOLOGIES,
	VENDOR_NVIDIA,
	VENDOR_CSR,
	VENDOR_MYRIAD,
	VENDOR_AMD,
	VENDOR_MESA,
	VENDOR_SUSE,
	VENDOR_OPEN_EMBEDDED,
	VENDOR_LAST = VENDOR_OPEN_EMBEDDED
} VendorType;

typedef enum
{
	VISIBLE_PUBLIC,
	VISIBLE_PRIVATE,
	VISIBLE_LOCAL,
} Visibility;

typedef enum
{
	X86_FEAT_ADX,
	X86_FEAT_AES,
	X86_FEAT_AMX_AVX512,
	X86_FEAT_AMX_FP8,
	X86_FEAT_AMX_MOVRS,
	X86_FEAT_AMX_TF32,
	X86_FEAT_AMX_TRANSPOSE,
	X86_FEAT_AMX_BF16,
	X86_FEAT_AMX_COMPLEX,
	X86_FEAT_AMX_FP16,
	X86_FEAT_AMX_INT8,
	X86_FEAT_AMX_TILE,
	X86_FEAT_APX_EGPR,
	X86_FEAT_APX_PUSH2POP2,
	X86_FEAT_APX_PPX,
	X86_FEAT_APX_NDD,
	X86_FEAT_APX_CCMP,
	X86_FEAT_APX_NF,
	X86_FEAT_APX_CF,
	X86_FEAT_APX_ZU,
	X86_FEAT_AVX,
	X86_FEAT_AVX10_1_512,
	X86_FEAT_AVX10_1_256,
	X86_FEAT_AVX10_2_512,
	X86_FEAT_AVX10_2_256,
	X86_FEAT_AVX2,
	X86_FEAT_AVX5124FMAPS,
	X86_FEAT_AVX5124VNNIW,
	X86_FEAT_AVX512BF16,
	X86_FEAT_AVX512BITALG,
	X86_FEAT_AVX512BW,
	X86_FEAT_AVX512CD,
	X86_FEAT_AVX512DQ,
	X86_FEAT_AVX512ER,
	X86_FEAT_AVX512F,
	X86_FEAT_AVX512FP16,
	X86_FEAT_AVX512IFMA,
	X86_FEAT_AVX512PF,
	X86_FEAT_AVX512VBMI,
	X86_FEAT_AVX512VBMI2,
	X86_FEAT_AVX512VL,
	X86_FEAT_AVX512VNNI,
	X86_FEAT_AVX512VP2INTERSECT,
	X86_FEAT_AVX512VPOPCNTDQ,
	X86_FEAT_AVXIFMA,
	X86_FEAT_AVXNECONVERT,
	X86_FEAT_AVXVNNI,
	X86_FEAT_AVXVNNIINT16,
	X86_FEAT_AVXVNNIINT8,
	X86_FEAT_BMI,
	X86_FEAT_BMI2,
	X86_FEAT_CLDEMOTE,
	X86_FEAT_CLFLUSHOPT,
	X86_FEAT_CLWB,
	X86_FEAT_CLZERO,
	X86_FEAT_CMOV,
	X86_FEAT_CMPCCXADD,
	X86_FEAT_CMPXCHG16B,
	X86_FEAT_CMPXCHG8B,
	X86_FEAT_CRC32,
	X86_FEAT_ENQCMD,
	X86_FEAT_EVEX512,
	X86_FEAT_F16C,
	X86_FEAT_FMA,
	X86_FEAT_FMA4,
	X86_FEAT_FSGSBASE,
	X86_FEAT_FXSR,
	X86_FEAT_GFNI,
	X86_FEAT_HRESET,
	X86_FEAT_INVPCID,
	X86_FEAT_KL,
	X86_FEAT_LWP,
	X86_FEAT_LZCNT,
	X86_FEAT_MMX,
	X86_FEAT_MOVBE,
	X86_FEAT_MOVDIR64B,
	X86_FEAT_MOVDIRI,
	X86_FEAT_MOVRS,
	X86_FEAT_MWAITX,
	X86_FEAT_PCLMUL,
	X86_FEAT_PCONFIG,
	X86_FEAT_PKU,
	X86_FEAT_POPCNT,
	X86_FEAT_PREFETCHI,
	X86_FEAT_PREFETCHWT1,
	X86_FEAT_PRFCHW,
	X86_FEAT_PTWRITE,
	X86_FEAT_RAOINT,
	X86_FEAT_RDPID,
	X86_FEAT_RDPRU,
	X86_FEAT_RDRND,
	X86_FEAT_RDSEED,
	X86_FEAT_RTM,
	X86_FEAT_SAHF,
	X86_FEAT_SERIALIZE,
	X86_FEAT_SGX,
	X86_FEAT_SHA,
	X86_FEAT_SHA512,
	X86_FEAT_SHSTK,
	X86_FEAT_SM3,
	X86_FEAT_SM4,
	X86_FEAT_SSE,
	X86_FEAT_SSE2,
	X86_FEAT_SSE3,
	X86_FEAT_SSE4_1,
	X86_FEAT_SSE4_2,
	X86_FEAT_SSE4_A,
	X86_FEAT_SSSE3,
	X86_FEAT_TBM,
	X86_FEAT_TSXLDTRK,
	X86_FEAT_UINTR,
	X86_FEAT_USERMSR,
	X86_FEAT_VAES,
	X86_FEAT_VPCLMULQDQ,
	X86_FEAT_VZEROUPPER,
	X86_FEAT_WAITPKG,
	X86_FEAT_WBNOINVD,
	X86_FEAT_WIDEKL,
	X86_FEAT_X87,
	X86_FEAT_XOP,
	X86_FEAT_XSAVE,
	X86_FEAT_XSAVEC,
	X86_FEAT_XSAVEOPT,
	X86_FEAT_XSAVES,
	X86_FEATURE_LAST = X86_FEAT_XSAVES,
} X86Feature;

// -- Arch helper macros
#define ARCH_UNSUPPORTED ARCH_TYPE_AARCH64_32: case ARCH_TYPE_BPFEL: case ARCH_TYPE_BPFEB: case ARCH_TYPE_SPARCEL: \
 case ARCH_TYPE_LE64: case ARCH_TYPE_AMDIL: case ARCH_TYPE_AMDIL64: case ARCH_TYPE_HSAIL: case ARCH_TYPE_HSAIL64:  \
 case ARCH_TYPE_KALIMBA: case ARCH_TYPE_SHAVE: case ARCH_TYPE_RSCRIPT32: case ARCH_TYPE_RSCRIPT64:                 \
 case ARCH_TYPE_LE32: case ARCH_TYPE_MIPS: case ARCH_TYPE_MIPSEL: case ARCH_TYPE_MIPS64EL: case ARCH_TYPE_MIPS64:  \
 case ARCH_TYPE_AVR: case ARCH_TYPE_NVPTX64: case ARCH_TYPE_NVPTX: case ARCH_TYPE_MSP430: case ARCH_TYPE_SYSTEMZ:  \
 case ARCH_TYPE_TCELE: case ARCH_TYPE_TCE: case ARCH_TYPE_LANAI: case ARCH_TYPE_HEXAGON: case ARCH_TYPE_AMDGCN:    \
 case ARCH_TYPE_R600: case ARCH_TYPE_SPARC: case ARCH_TYPE_SPARCV9: case ARCH_TYPE_XCORE: case ARCH_TYPE_ARC:      \
 case ARCH_TYPE_SPIR64: case ARCH_TYPE_SPIR

// -- AST helper macros
#define CT_AST \
 AST_CT_ASSERT: case AST_CT_ECHO_STMT: case AST_CT_ELSE_STMT: \
 case AST_CT_FOREACH_STMT: case AST_CT_FOR_STMT: \
 case AST_CT_IF_STMT: case AST_CT_SWITCH_STMT

// -- Decl helper macros
#define NON_TYPE_DECLS DECL_IMPORT: case DECL_MACRO: \
	case DECL_DECLARRAY: case DECL_ATTRIBUTE: case DECL_LABEL: \
	case DECL_DEFINE: case DECL_CT_ASSERT: case DECL_CT_EXEC: \
	case DECL_CT_ECHO: case DECL_CT_INCLUDE: case DECL_GLOBALS: \
	case DECL_BODYPARAM: case DECL_VAR: case DECL_ENUM_CONSTANT: case DECL_FAULTVALUE: \
	case DECL_POISONED

// -- Expr helper macros
#define NON_RUNTIME_EXPR EXPR_POISONED: \
		case EXPR_CT_DEFINED: case EXPR_CT_AND_OR:\
		case EXPR_CT_CASTABLE: case EXPR_CT_IS_CONST: \
		case EXPR_CT_ARG: case EXPR_TYPEINFO: case EXPR_CT_IDENT: case EXPR_HASH_IDENT: \
		case EXPR_COMPILER_CONST: case EXPR_CT_CALL:  \
		case EXPR_SPLAT: case EXPR_ANYSWITCH: case EXPR_STRINGIFY: case EXPR_TYPECALL: \
		case EXPR_CT_EVAL: case EXPR_CT_CONCAT: case EXPR_CT_APPEND

static_assert(EXPR_LAST < 128, "Too many expression types");

// -- OsType helper macros
#define OS_DARWIN_TYPES OS_TYPE_WATCHOS: case OS_TYPE_IOS: case OS_TYPE_TVOS: case OS_TYPE_MACOSX
#define OS_UNSUPPORTED OS_TYPE_AIX: case OS_TYPE_HAIKU: case OS_TYPE_ANANAS: case OS_TYPE_CLOUD_ABI: \
 case OS_TYPE_DRAGON_FLY: case OS_TYPE_FUCHSIA: case OS_TYPE_KFREEBSD: case OS_TYPE_PS3: case OS_TYPE_RTEMS: \
 case OS_TYPE_SOLARIS: case OS_TYPE_MINIX: case OS_TYPE_NACL: case OS_TYPE_CNK: case OS_TYPE_CUDA:   \
 case OS_TYPE_NVOPENCL: case OS_TYPE_AMDHSA: case OS_TYPE_PS4: case OS_TYPE_ELFIAMCU: case OS_TYPE_MESA3D:   \
 case OS_TYPE_CONTIKI: case OS_TYPE_AMDPAL: case OS_TYPE_HERMITCORE: case OS_TYPE_HURD: case OS_TYPE_EMSCRIPTEN

// Token helper macros

#define NON_VOID_TYPE_TOKENS \
  TOKEN_BOOL: case TOKEN_CHAR: case TOKEN_DOUBLE: case TOKEN_FLOAT: \
  case TOKEN_FLOAT16: case TOKEN_BFLOAT: case TOKEN_INT128: case TOKEN_ICHAR: case TOKEN_INT: \
  case TOKEN_IPTR: case TOKEN_LONG: \
  case TOKEN_SHORT: case TOKEN_UINT128: case TOKEN_UINT: case TOKEN_ULONG:  \
  case TOKEN_UPTR: case TOKEN_USHORT: case TOKEN_UCHAR: case TOKEN_USZ: \
  case TOKEN_ISZ: case TOKEN_FLOAT128: case TOKEN_TYPEID: case TOKEN_ANYFAULT: case TOKEN_ANY
#define TYPE_TOKENS NON_VOID_TYPE_TOKENS: case TOKEN_VOID
#define CT_TYPE_TOKENS TOKEN_CT_TYPE_IDENT: case TOKEN_CT_TYPEOF: case TOKEN_CT_EVALTYPE: \
	case TOKEN_CT_VATYPE: case TOKEN_CT_TYPEFROM
#define TYPELIKE_TOKENS TYPE_TOKENS: case TOKEN_TYPE_IDENT: case CT_TYPE_TOKENS

// -- Types helper macros
#define FLATTENED_TYPES TYPE_DISTINCT: case TYPE_OPTIONAL: case TYPE_TYPEDEF
#define ALL_SIGNED_INTS TYPE_I8: case TYPE_I16: case TYPE_I32: case TYPE_I64: case TYPE_I128
#define ALL_UNSIGNED_INTS TYPE_U8: case TYPE_U16: case TYPE_U32: case TYPE_U64: case TYPE_U128
#define ALL_FLOATS TYPE_BF16: case TYPE_F16: case TYPE_F32: case TYPE_F64: case TYPE_F128

#define LOWERED_TYPES CT_TYPES: case TYPE_ENUM: case TYPE_TYPEDEF: case TYPE_TYPEID: \
  case TYPE_DISTINCT: case TYPE_ANYFAULT: case TYPE_FAULTTYPE: case TYPE_BITSTRUCT: \
  case TYPE_OPTIONAL: case TYPE_INTERFACE

#define CT_TYPES TYPE_TYPEINFO: case TYPE_INFERRED_ARRAY: case TYPE_INFERRED_VECTOR: case TYPE_UNTYPED_LIST: \
case TYPE_POISONED: case TYPE_MEMBER: case TYPE_WILDCARD

#define ALL_INTS TYPE_I8: case TYPE_I16: case TYPE_I32: case TYPE_I64: case TYPE_I128: \
case TYPE_U8: case TYPE_U16: case TYPE_U32: case TYPE_U64: case TYPE_U128

#define UNRESOLVED_EXPRS EXPR_TRY_UNRESOLVED: case EXPR_ACCESS_UNRESOLVED: \
	case EXPR_CATCH_UNRESOLVED: case EXPR_UNRESOLVED_IDENTIFIER: case EXPR_CAST: \
	case EXPR_TYPEID: case EXPR_EMBED: case EXPR_VASPLAT: case EXPR_OTHER_CONTEXT: \
	case EXPR_GENERIC_IDENT: case EXPR_COMPOUND_LITERAL: case EXPR_MACRO_BODY: case EXPR_CT_SUBSCRIPT


