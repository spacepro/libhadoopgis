/** @file cmdline.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.5
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef CMDLINE_H
#define CMDLINE_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
/** @brief the program name (used for printing errors) */
#define CMDLINE_PARSER_PACKAGE "Hadoop-GIS"
#endif

#ifndef CMDLINE_PARSER_PACKAGE_NAME
/** @brief the complete program name (used for help and version) */
#define CMDLINE_PARSER_PACKAGE_NAME "Hadoop-GIS"
#endif

#ifndef CMDLINE_PARSER_VERSION
/** @brief the program version */
#define CMDLINE_PARSER_VERSION "0.01"
#endif

/** @brief Where the command line options are stored */
struct gengetopt_args_info
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  double min_x_arg;	/**< @brief Minimum horizontal coordinate of the spatial universe.  */
  char * min_x_orig;	/**< @brief Minimum horizontal coordinate of the spatial universe original value given at command line.  */
  const char *min_x_help; /**< @brief Minimum horizontal coordinate of the spatial universe help description.  */
  double max_x_arg;	/**< @brief Maximum horizontal coordinate of the spatial universe.  */
  char * max_x_orig;	/**< @brief Maximum horizontal coordinate of the spatial universe original value given at command line.  */
  const char *max_x_help; /**< @brief Maximum horizontal coordinate of the spatial universe help description.  */
  double min_y_arg;	/**< @brief Minimum vertical coordinate of the spatial universe.  */
  char * min_y_orig;	/**< @brief Minimum vertical coordinate of the spatial universe original value given at command line.  */
  const char *min_y_help; /**< @brief Minimum vertical coordinate of the spatial universe help description.  */
  double max_y_arg;	/**< @brief Maximum vertical coordinate of the spatial universe.  */
  char * max_y_orig;	/**< @brief Maximum vertical coordinate of the spatial universe original value given at command line.  */
  const char *max_y_help; /**< @brief Maximum vertical coordinate of the spatial universe help description.  */
  int x_split_arg;	/**< @brief Number of split in horizontal direction.  */
  char * x_split_orig;	/**< @brief Number of split in horizontal direction original value given at command line.  */
  const char *x_split_help; /**< @brief Number of split in horizontal direction help description.  */
  int y_split_arg;	/**< @brief Number of split in vertical direction.  */
  char * y_split_orig;	/**< @brief Number of split in vertical direction original value given at command line.  */
  const char *y_split_help; /**< @brief Number of split in vertical direction help description.  */
  int geom_arg;	/**< @brief geometry field index.  */
  char * geom_orig;	/**< @brief geometry field index original value given at command line.  */
  const char *geom_help; /**< @brief geometry field index help description.  */
  int uid_arg;	/**< @brief uid field index.  */
  char * uid_orig;	/**< @brief uid field index original value given at command line.  */
  const char *uid_help; /**< @brief uid field index help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int min_x_given ;	/**< @brief Whether min-x was given.  */
  unsigned int max_x_given ;	/**< @brief Whether max-x was given.  */
  unsigned int min_y_given ;	/**< @brief Whether min-y was given.  */
  unsigned int max_y_given ;	/**< @brief Whether max-y was given.  */
  unsigned int x_split_given ;	/**< @brief Whether x-split was given.  */
  unsigned int y_split_given ;	/**< @brief Whether y-split was given.  */
  unsigned int geom_given ;	/**< @brief Whether geom was given.  */
  unsigned int uid_given ;	/**< @brief Whether uid was given.  */

} ;

/** @brief The additional parameters to pass to parser functions */
struct cmdline_parser_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure gengetopt_args_info (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure gengetopt_args_info (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *gengetopt_args_info_purpose;
/** @brief the usage string of the program */
extern const char *gengetopt_args_info_usage;
/** @brief all the lines making the help output */
extern const char *gengetopt_args_info_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser (int argc, char **argv,
  struct gengetopt_args_info *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_ext() instead
 */
int cmdline_parser2 (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_ext (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  struct cmdline_parser_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_dump(FILE *outfile,
  struct gengetopt_args_info *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_file_save(const char *filename,
  struct gengetopt_args_info *args_info);

/**
 * Print the help
 */
void cmdline_parser_print_help(void);
/**
 * Print the version
 */
void cmdline_parser_print_version(void);

/**
 * Initializes all the fields a cmdline_parser_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void cmdline_parser_params_init(struct cmdline_parser_params *params);

/**
 * Allocates dynamically a cmdline_parser_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized cmdline_parser_params structure
 */
struct cmdline_parser_params *cmdline_parser_params_create(void);

/**
 * Initializes the passed gengetopt_args_info structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void cmdline_parser_init (struct gengetopt_args_info *args_info);
/**
 * Deallocates the string fields of the gengetopt_args_info structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void cmdline_parser_free (struct gengetopt_args_info *args_info);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int cmdline_parser_required (struct gengetopt_args_info *args_info,
  const char *prog_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMDLINE_H */
