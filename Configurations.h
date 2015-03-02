#pragma once

//#include <C:\Users\Blake\Documents\GitHub\pCT_Reconstruction\pCT_Reconstruction.h>

typedef unsigned long long ULL;
typedef unsigned int uint;

// 32 uint (128), 1 int (4), 38 double (304), 22 bool (22) = 458 + padding = 464
struct configurations
{
	//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	//----------------------------------------------------------------------- Output option parameters ------------------------------------------------------------------------//
	//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	// 14 uint, 23 double,
	//char* PROJECTION_DATA_DIR, * PREPROCESSING_DIR_D, * RECONSTRUCTION_DIR_D;
	//char* OBJECT_D, * RUN_DATE_D, * RUN_NUMBER_D, * PROJECTION_DATA_DATE_D, * PREPROCESS_DATE_D, * RECONSTRUCTION_DATE_D;
	double RECON_CYL_RADIUS_D, RECON_CYL_DIAMETER_D, RECON_CYL_HEIGHT_D, IMAGE_WIDTH_D, IMAGE_HEIGHT_D, IMAGE_THICKNESS_D, VOXEL_WIDTH_D, VOXEL_HEIGHT_D, VOXEL_THICKNESS_D, SLICE_THICKNESS_D;
	double X_ZERO_COORDINATE_D, Y_ZERO_COORDINATE_D, Z_ZERO_COORDINATE_D, RAM_LAK_TAU_D;
	double GANTRY_ANGLE_INTERVAL_D, ANGULAR_BIN_SIZE_D, SSD_T_SIZE_D, SSD_V_SIZE_D, T_SHIFT_D, U_SHIFT_D, V_SHIFT_D, T_BIN_SIZE_D, V_BIN_SIZE_D;
	double LAMBDA_D, LAMBDA, ETA_D, HULL_FILTER_THRESHOLD_D, FBP_AVG_THRESHOLD_D, X_0_FILTER_THRESHOLD_D;
	double SC_THRESHOLD_D, MSC_THRESHOLD_D, SM_LOWER_THRESHOLD_D, SM_UPPER_THRESHOLD_D, SM_SCALE_THRESHOLD_D;
	double VOXEL_STEP_SIZE_D, MLP_U_STEP_D, CONSTANT_CHORD_NORM_D, CONSTANT_LAMBDA_SCALE_D;

	uint NUM_SCANS_D, MAX_GPU_HISTORIES_D, MAX_CUTS_HISTORIES_D, T_BINS_D, V_BINS_D, COLUMNS_D, ROWS_D, SLICES_D, SIGMAS_2_KEEP_D;
	uint GANTRY_ANGLES_D, NUM_FILES_D, ANGULAR_BINS_D, NUM_BINS_D, NUM_VOXELS_D;
	uint SIZE_BINS_CHAR_D, SIZE_BINS_BOOL_D, SIZE_BINS_INT_D, SIZE_BINS_UINT_D, SIZE_BINS_FLOAT_D, SIZE_IMAGE_CHAR_D;
	uint SIZE_IMAGE_BOOL_D, SIZE_IMAGE_INT_D, SIZE_IMAGE_UINT_D, SIZE_IMAGE_FLOAT_D, SIZE_IMAGE_DOUBLE_D;
	uint ITERATIONS_D, BLOCK_SIZE_D, HULL_FILTER_RADIUS_D, X_0_FILTER_RADIUS_D, FBP_AVG_RADIUS_D, FBP_MEDIAN_RADIUS_D;	
	uint MSC_DIFF_THRESH_D;	

	int PSI_SIGN_D;

	bool FBP_ON_D, AVG_FILTER_FBP_D, MEDIAN_FILTER_FBP_D, IMPORT_FILTERED_FBP_D, SC_ON_D, MSC_ON_D, SM_ON_D;
	bool AVG_FILTER_HULL_D, AVG_FILTER_ITERATE_D, MLP_FILE_EXISTS_D, HISTORIES_FILE_EXISTS_D, REPERFORM_PREPROCESSING_D, PREPROCESSING_REQUIRED_D;
	bool WRITE_MSC_COUNTS_D, WRITE_SM_COUNTS_D, WRITE_X_FBP_D, WRITE_FBP_HULL_D, WRITE_AVG_FBP_D, WRITE_MEDIAN_FBP_D, WRITE_BIN_WEPLS_D, WRITE_WEPL_DISTS_D, WRITE_SSD_ANGLES_D;	
	//*************************************************************************************************************************************************************************//
	//*********************************************************************** Output option parameters ************************************************************************//
	//*************************************************************************************************************************************************************************//
	configurations
	(
		//char* projection_data_dir		= "D:\\pCT_Data\\Output",							
		//char* preprocessing_dir_d 		= "CTP404\\input_CTP404_4M",
		//char* reconstruction_dir_d 		= "CTP404\\input_CTP404_4M\\Robust2\\ETA0001",
		//char* object_d					= "Object",
		//char* run_date_d				= "MMDDYYYY",
		//char* run_number_d				= "Run",
		//char* projection_data_date_d	= "MMDDYYYY",
		//char* preprocess_date_d			= "MMDDYYYY",
		//char* reconstruction_date_d		= "MMDDYYYY",
		uint num_scans_d 				= 1,								// [#] Total number of scans of same object
		uint max_gpu_histories_d		= 1500000,							// [#] Number of histories to process on the GPU at a time, based on GPU capacity
		uint max_cuts_histories_d 		= 1500000,	
		uint columns_d 					= 200,
		uint rows_d 					= 200.4,
		//uint slices_d 					= 32,
		uint sigmas_2_keep_d 			= 3,
		double gantry_angle_interval_d 	= 4,
		double angular_bin_size_d 		= 4.0,
		double ssd_t_size_d 			= 35.0,
		double ssd_v_size_d 			= 9.0,
		double t_shift_d 				= 0.0,
		double u_shift_d 				= 0.0,
		double v_shift_d 				= 0.0,
		double t_bin_size_d 			= 0.1,
		double v_bin_size_d 			= 0.25,
		double recon_cyl_radius_d 		= 10.0,
		double slice_thickness_d 		= 0.25,
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
		//----------------------------------------------------------------------- Output option parameters ------------------------------------------------------------------------//
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
		uint iterations_d				= 12,								// [#] of iterations through the entire set of histories to perform in iterative image reconstruction
		uint block_size_d				= 60,								// [#] of paths to use for each update: ART = 1, 
		uint hull_filter_radius_d 		= 1,								// [#] Averaging filter neighborhood radius in: [voxel - AVG_FILTER_SIZE, voxel + AVG_FILTER_RADIUS]
		uint x_0_filter_radius_d		= 3,
		uint fbp_avg_radius_d			= 1,
		uint fbp_median_radius_d		= 3,	
		int psi_sign_d					= 1,
		double lambda_d 				= 0.0001,
		double eta_d                    = 0.0001,
		double hull_filter_threshold_d	= 0.1,								// [#] Threshold ([0.0, 1.0]) used by averaging filter to identify voxels belonging to the hull
		double fbp_avg_threshold_d		= 0.1,
		double x_0_filter_threshold_d	= 0.1,
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
		//----------------------------------------------------------------------- Output option parameters ------------------------------------------------------------------------//
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
		uint msc_diff_thresh_d			= 50,								// [#] Threshold on difference in counts between adjacent voxels used by MSC for edge detection
		double sc_threshold_d			= 0.0,								// [cm] If WEPL < SC_THRESHOLD, SC assumes the proton missed the object
		double msc_threshold_d			= 0.0,								// [cm] If WEPL < MSC_THRESHOLD, MSC assumes the proton missed the object
		double sm_lower_threshold_d		= 6.0,								// [cm] If WEPL >= SM_THRESHOLD, SM assumes the proton passed through the object
		double sm_upper_threshold_d		= 21.0,								// [cm] If WEPL > SM_UPPER_THRESHOLD, SM ignores this history
		double sm_scale_threshold_d		= 1.0,								// [cm] Threshold scaling factor used by SM to adjust edge detection sensitivity
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
		//----------------------------------------------------------------------- Output option parameters ------------------------------------------------------------------------//
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
		bool fbp_on_d					= true,								// [T/F] Turn FBP on (T) or off (F)
		bool avg_filter_fbp_d			= false,							// [T/F] Apply averaging filter to initial iterate (T) or not (F)
		bool median_filter_fbp_d		= false,
		bool import_filtered_fbp_d		= false,
		bool sc_on_d					= false,							// [T/F] Turn Space Carving on (T) or off (F)
		bool msc_on_d					= true,								// [T/F] Turn Modified Space Carving on (T) or off (F)
		bool sm_on_d					= false,							// [T/F] Turn Space Modeling on (T) or off (F)
		bool avg_filter_hull_d			= true,								// [T/F] Apply averaging filter to hull (T) or not (F)
		bool avg_filter_iterate_d		= false,							// [T/F] Apply averaging filter to initial iterate (T) or not (F)
		bool mlp_file_exists_d			= false,
		bool histories_file_exists_d	= false,
		bool reperform_preprocessing_d	= false,
		bool preprocessing_required_d	= false,
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
		//----------------------------------------------------------------------- Output option parameters ------------------------------------------------------------------------//
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
		bool write_msc_counts_d			= true,								// [T/F] Write MSC counts array to disk (T) or not (F) before performing edge detection 
		bool write_sm_counts_d			= true,								// [T/F] Write SM counts array to disk (T) or not (F) before performing edge detection 
		bool write_x_fbp_d				= true,								// [T/F] Write FBP image before thresholding to disk (T) or not (F)
		bool write_fbp_hull_d			= true,								// [T/F] Write FBP hull to disk (T) or not (F)
		bool write_avg_fbp_d			= true,								// [T/F] Write average filtered FBP image before thresholding to disk (T) or not (F)
		bool write_median_fbp_d			= false,							// [T/F] Write median filtered FBP image to disk (T) or not (F)
		bool write_bin_wepls_d			= false,							// [T/F] Write WEPLs for each bin to disk (T) for WEPL distribution analysis, or do not (F)
		bool write_wepl_dists_d			= false,							// [T/F] Write mean WEPL values to disk (T) or not (F): t bin = columns, v bin = rows, 1 angle per file
		bool write_ssd_angles_d			= false								// [T/F] Write angles for each proton through entry/exit tracker planes to disk (T), or do not (F)
	):
	//*************************************************************************************************************************************************************************//
	//*********************************************************************** Parameter Instantiations ************************************************************************//
	//*************************************************************************************************************************************************************************//
	//PROJECTION_DATA_DIR(projection_data_dir),
	//PREPROCESSING_DIR_D(preprocessing_dir_d),
	//RECONSTRUCTION_DIR_D(reconstruction_dir_d),
	//OBJECT_D(object_d),
	//RUN_DATE_D(run_date_d),
	//RUN_NUMBER_D(run_number_d),
	//PROJECTION_DATA_DATE_D(projection_data_date_d),
	//PREPROCESS_DATE_D(preprocess_date_d),
	//RECONSTRUCTION_DATE_D(reconstruction_date_d),
	NUM_SCANS_D(num_scans_d),												// [#] Total number of scans of same object
	NUM_FILES_D( NUM_SCANS_D * GANTRY_ANGLES_D ),							// [#] 1 file per gantry angle per translation
	MAX_GPU_HISTORIES_D(max_gpu_histories_d),								// [#] Number of histories to process on the GPU at a time, based on GPU capacity
	MAX_CUTS_HISTORIES_D(max_cuts_histories_d),								// [#] Number of histories to process on the GPU at a time, based on GPU capacity
	GANTRY_ANGLE_INTERVAL_D(gantry_angle_interval_d),						// [degrees] Angle between successive projection angles
	GANTRY_ANGLES_D(uint( 360 / GANTRY_ANGLE_INTERVAL_D )),					// [#] Total number of projection angles
	ANGULAR_BIN_SIZE_D(angular_bin_size_d),									// [degrees] Angle between adjacent bins in angular (rotation) direction
	SSD_T_SIZE_D(ssd_t_size_d),												// [cm] Length of SSD in t (lateral) direction
	SSD_V_SIZE_D(ssd_v_size_d),												// [cm] Length of SSD in v (lateral) direction
	T_BINS_D(uint( ssd_t_size_d / t_bin_size_d + 0.5 )),					// [#] Number of bins (i.e. quantization levels) for t (lateral) direction 
	V_BINS_D(uint( ssd_v_size_d / v_bin_size_d + 0.5 )),					// [#] Number of bins (i.e. quantization levels) for v (vertical) direction
	ANGULAR_BINS_D(uint( 360 / ANGULAR_BIN_SIZE_D + 0.5 )),					// [#] Number of bins (i.e. quantization levels) for path angle 
	NUM_BINS_D( ANGULAR_BINS_D * T_BINS_D * V_BINS_D ),						// [#] Total number of bins corresponding to possible 3-tuples [ANGULAR_BIN, T_BIN, V_BIN],
	SIGMAS_2_KEEP_D(sigmas_2_keep_d),										// [#] Number of standard deviations from mean to allow before cutting the history 
	COLUMNS_D(columns_d),													// [#] Number of voxels in the x direction (i.e., number of columns) of image
	ROWS_D(rows_d),															// [#] Number of voxels in the y direction (i.e., number of rows) of image
	SLICES_D(uint( RECON_CYL_HEIGHT_D / slice_thickness_d)),				// [#] Number of voxels in the z direction (i.e., number of slices) of image
	NUM_VOXELS_D( COLUMNS_D * ROWS_D * SLICES_D ),							// [#] Total number of voxels (i.e. 3-tuples [column, row, slice]) in image	
	T_SHIFT_D(t_shift_d),													// [cm] Amount by which to shift all t coordinates on input
	U_SHIFT_D(u_shift_d),													// [cm] Amount by which to shift all u coordinates on input
	V_SHIFT_D(v_shift_d),													// [cm] Amount by which to shift all v coordinates on input
	T_BIN_SIZE_D(t_bin_size_d),												// [cm] Distance between adjacent bins in t (lateral) direction
	V_BIN_SIZE_D(v_bin_size_d),												// [cm] Distance between adjacent bins in v (lateral) direction
	RECON_CYL_RADIUS_D(recon_cyl_radius_d),									// [cm] Radius of reconstruction cylinder
	RECON_CYL_DIAMETER_D( 2 * RECON_CYL_RADIUS_D ),							// [cm] Diameter of reconstruction cylinder
	RECON_CYL_HEIGHT_D(SSD_V_SIZE_D - 1.0),									// [cm] Height of reconstruction cylinder
	IMAGE_WIDTH_D(RECON_CYL_DIAMETER_D),									// [cm] Distance between left and right edges of each slice in image
	IMAGE_HEIGHT_D(RECON_CYL_DIAMETER_D),									// [cm] Distance between top and bottom edges of each slice in image
	IMAGE_THICKNESS_D(RECON_CYL_HEIGHT_D),									// [cm] Distance between bottom of bottom slice and top of the top slice of image
	VOXEL_WIDTH_D(RECON_CYL_DIAMETER_D / COLUMNS_D),						// [cm] distance between left and right edges of each voxel in image
	VOXEL_HEIGHT_D(RECON_CYL_DIAMETER_D / ROWS_D),							// [cm] distance between top and bottom edges of each voxel in image
	VOXEL_THICKNESS_D(slice_thickness_d),									// [cm] distance between top and bottom of each slice in image
	SLICE_THICKNESS_D(slice_thickness_d),									// [cm] distance between top and bottom of each slice in image
	X_ZERO_COORDINATE_D(-RECON_CYL_RADIUS_D),								// [cm] x-coordinate corresponding to left edge of 1st voxel (i.e. column) in image space
	Y_ZERO_COORDINATE_D(RECON_CYL_RADIUS_D),								// [cm] y-coordinate corresponding to top edge of 1st voxel (i.e. row) in image space
	Z_ZERO_COORDINATE_D(RECON_CYL_HEIGHT_D/2),								// [cm] z-coordinate corresponding to top edge of 1st voxel (i.e. slice) in image space
	RAM_LAK_TAU_D(2/sqrt(2.0) * T_BIN_SIZE_D),								// [#] Defines tau in Ram-Lak filter calculation, estimated from largest frequency in slice 
	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	/*---------------------------------------------------------- Memory allocation size for arrays (binning, image) -----------------------------------------------------------*/
	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	SIZE_BINS_CHAR_D(	NUM_BINS_D		* sizeof(char)	),					// [bytes] Amount of memory required for a character array used for binning
	SIZE_BINS_BOOL_D(	NUM_BINS_D		* sizeof(bool)	),					// [bytes] Amount of memory required for a boolean array used for binning
	SIZE_BINS_INT_D(	NUM_BINS_D		* sizeof(int)	),					// [bytes] Amount of memory required for an integer array used for binning
	SIZE_BINS_UINT_D(	NUM_BINS_D		* sizeof(uint)	),					// [bytes] Amount of memory required for an unsigned integer array used for binning
	SIZE_BINS_FLOAT_D(	NUM_BINS_D		* sizeof(float)	),					// [bytes] Amount of memory required for a floating point array used for binning
	SIZE_IMAGE_CHAR_D(	NUM_VOXELS_D	* sizeof(char)	),					// [bytes] Amount of memory required for a character array used for binning
	SIZE_IMAGE_BOOL_D(	NUM_VOXELS_D	* sizeof(bool)	),					// [bytes] Amount of memory required for a boolean array used for binning
	SIZE_IMAGE_INT_D(	NUM_VOXELS_D	* sizeof(int)	),					// [bytes] Amount of memory required for an integer array used for binning
	SIZE_IMAGE_UINT_D(	NUM_VOXELS_D	* sizeof(uint)	),					// [bytes] Amount of memory required for an unsigned integer array used for binning
	SIZE_IMAGE_FLOAT_D(	NUM_VOXELS_D	* sizeof(float)	),					// [bytes] Amount of memory required for a floating point array used for binning
	SIZE_IMAGE_DOUBLE_D(NUM_VOXELS_D	* sizeof(double)),					// [bytes] Amount of memory required for a floating point array used for binning
	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	/*-------------------------------------------------------------- Iterative Image Reconstruction Parameters ----------------------------------------------------------------*/
	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	VOXEL_STEP_SIZE_D( VOXEL_WIDTH_D / 2 ),									// [cm] Length of the step taken along the path, i.e. change in depth per step for
	MLP_U_STEP_D( VOXEL_WIDTH_D / 2),										// [cm] Size of the step taken along u direction during MLP; depth difference between successive MLP points
	CONSTANT_CHORD_NORM_D(pow(VOXEL_WIDTH_D, 2.0)),							// [cm^2] Precalculated value of ||a_i||^2 for use of constant chord length
	CONSTANT_LAMBDA_SCALE_D(VOXEL_WIDTH_D * LAMBDA_D),						// [cm] Precalculated value of |a_i| * LAMBDA for use of constant chord length
	////-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	////----------------------------------------------------------------------- output option parameters ------------------------------------------------------------------------//
	////-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	ITERATIONS_D(iterations_d),												// # of iterations through the entire set of histories to perform in iterative image reconstruction
	BLOCK_SIZE_D(block_size_d),												// # of paths to use for each update: ART = 1, 
	HULL_FILTER_RADIUS_D(hull_filter_radius_d),								// [#] Filter neighborhood radius in: [voxel - AVG_FILTER_SIZE, voxel + AVG_FILTER_RADIUS]	
	X_0_FILTER_RADIUS_D(x_0_filter_radius_d),								// [#] Filter neighborhood radius in: [voxel - AVG_FILTER_SIZE, voxel + AVG_FILTER_RADIUS]
	FBP_AVG_RADIUS_D(fbp_avg_radius_d),										// [#] Averaging filter neighborhood radius in: [voxel - AVG_FILTER_SIZE, voxel + AVG_FILTER_RADIUS]
	FBP_MEDIAN_RADIUS_D(fbp_median_radius_d),								// [#] Median filter neighborhood radius in: [voxel - AVG_FILTER_SIZE, voxel + AVG_FILTER_RADIUS]
	PSI_SIGN_D(psi_sign_d),													// [+1/-1] Sign specifying the sign to use for Psi in scaling residual for updates in robust technique to reconstruction	
	LAMBDA_D(lambda_d),														// [#] Relaxation parameter used in update calculations in reconstruction algorithms
	LAMBDA(lambda_d),														// [#] Relaxation parameter used in update calculations in reconstruction algorithms
	ETA_D(eta_d),															// [#] Value used in calculation of Psi = (1-x_i) * ETA used in robust technique to reconstruction
	HULL_FILTER_THRESHOLD_D(hull_filter_threshold_d),						// [#] Threshold ([0.0, 1.0]) used by averaging filter to identify voxels belonging to the hull							
	FBP_AVG_THRESHOLD_D(fbp_avg_threshold_d),								// [#] Threshold ([0.0, 1.0]) used by averaging filter to identify voxels belonging to the FBP image
	X_0_FILTER_THRESHOLD_D(x_0_filter_threshold_d),							// [#] Threshold ([0.0, 1.0]) used by averaging filter to identify voxels belonging to the initial iterate x_0
	////-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	////----------------------------------------------------------------------- output option parameters ------------------------------------------------------------------------//
	////-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	MSC_DIFF_THRESH_D(msc_diff_thresh_d),									// [#] Threshold on difference in counts between adjacent voxels used by MSC for edge detection
	SC_THRESHOLD_D(sc_threshold_d),											// [cm] If WEPL < SC_THRESHOLD, SC assumes the proton missed the object
	MSC_THRESHOLD_D(msc_threshold_d),										// [cm] If WEPL < MSC_THRESHOLD, MSC assumes the proton missed the object
	SM_LOWER_THRESHOLD_D(sm_lower_threshold_d),								// [cm] If WEPL >= SM_THRESHOLD, SM assumes the proton passed through the object
	SM_UPPER_THRESHOLD_D(sm_upper_threshold_d),								// [cm] If WEPL > SM_UPPER_THRESHOLD, SM ignores this history
	SM_SCALE_THRESHOLD_D(sm_scale_threshold_d),								// [cm] Threshold scaling factor used by SM to adjust edge detection sensitivity
	////-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	////----------------------------------------------------------------------- Specify which preprocessing  ------------------------------------------------------------------------//
	////-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	FBP_ON_D(fbp_on_d),														// [T/F] Turn FBP on (T) or off (F)
	AVG_FILTER_FBP_D(avg_filter_fbp_d),										// [T/F] Apply averaging filter to initial iterate (T) or not (F)
	MEDIAN_FILTER_FBP_D(median_filter_fbp_d),								// [T/F] Apply median filtering to FBP (T) or not (F)
	IMPORT_FILTERED_FBP_D(import_filtered_fbp_d),							// [T/F] Import filtered FBP from disk (T) or not (F)
	SC_ON_D(sc_on_d),														// [T/F] Turn Space Carving on (T) or off (F)
	MSC_ON_D(msc_on_d),														// [T/F] Turn Modified Space Carving on (T) or off (F)
	SM_ON_D(sm_on_d),														// [T/F] Turn Space Modeling on (T) or off (F)
	AVG_FILTER_HULL_D(avg_filter_hull_d),									// [T/F] Apply averaging filter to hull (T) or not (F)	
	AVG_FILTER_ITERATE_D(avg_filter_iterate_d),								// [T/F] Apply averaging filter to initial iterate x_0 (T) or not (F)	
	MLP_FILE_EXISTS_D(mlp_file_exists_d),									// [T/F] MLP.bin preprocessing data exists (T) or not (F)
	HISTORIES_FILE_EXISTS_D(histories_file_exists_d),						// [T/F] Histories.bin preprocessing data exists (T) or not (F)
	REPERFORM_PREPROCESSING_D(reperform_preprocessing_d),					// [T/F] Perform preproessing and overwite any existing data for (T) or not (F)
	PREPROCESSING_REQUIRED_D(preprocessing_required_d),						// [T/F] Preexisting preprocessing data exists (T) or not (F)
	////-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	////--------------------------------------------------------- Control of writing optional intermediate data to disk  --------------------------------------------------------//
	////-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
	WRITE_MSC_COUNTS_D(write_msc_counts_d),									// [T/F] Write MSC counts array to disk (T) or not (F) before performing edge detection 
	WRITE_SM_COUNTS_D(write_sm_counts_d),									// [T/F] Write SM counts array to disk (T) or not (F) before performing edge detection 
	WRITE_X_FBP_D(write_x_fbp_d),											// [T/F] Write FBP image before thresholding to disk (T) or not (F)
	WRITE_FBP_HULL_D(write_fbp_hull_d),										// [T/F] Write FBP hull to disk (T) or not (F)
	WRITE_AVG_FBP_D(write_avg_fbp_d),										// [T/F] Write average filtered FBP image before thresholding to disk (T) or not (F)
	WRITE_MEDIAN_FBP_D(write_median_fbp_d),									// [T/F] Write median filtered FBP image to disk (T) or not (F)
	WRITE_BIN_WEPLS_D(write_bin_wepls_d),									// [T/F] Write WEPLs for each bin to disk (T) for WEPL distribution analysis, or do not (F)
	WRITE_WEPL_DISTS_D(write_wepl_dists_d),									// [T/F] Write mean WEPL values to disk (T) or not (F): t bin = columns, v bin = rows, 1 angle per file
	WRITE_SSD_ANGLES_D(write_ssd_angles_d)									// [T/F] Write angles for each proton through entry/exit tracker planes to disk (T), or do not (F)
	{};
};

configurations parameters;
configurations parameter_container;
configurations *parameters_h = &parameter_container;
configurations *parameters_d;